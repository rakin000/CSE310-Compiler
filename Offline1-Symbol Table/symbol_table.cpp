#include <bits/stdc++.h>
using namespace std ;
// #define PROMPT 1

class symbol{
    string name;
    string type;
    public:
    symbol *next;
    symbol(){
        next = nullptr;
    }
    symbol(string name,string type){
        this->name=name;
        this->type=type;
        next = nullptr;
    }
    ~symbol(){
        delete next;
    }

    string& getName(){
        return name;
    }
    string& getType(){
        return type;
    }
};

class scope_table{
    scope_table *parent_scope;
    int child_count;
    string id ;
    vector<symbol*> table;
    public:
    scope_table(int size,scope_table *p=nullptr){
        table.assign(size,nullptr);
        this->parent_scope = p;
        if( parent_scope != nullptr )
            parent_scope->child_count++;
        if( parent_scope != nullptr )
            this->id = parent_scope->id+"."+to_string(parent_scope->child_count);
        else this->id = "1";
        this->child_count = 0;
#ifdef PROMPT
        cout<<"New ScopeTable with id "<<this->id<<" created"<<endl;
#endif
    }
    scope_table():
        scope_table(1024,nullptr)
    {
    }
    ~scope_table(){
        for(int i=0;i<table.size();i++)
            delete table[i];
#ifdef PROMPT
        cout<<"ScopeTable with id "<<id<<" removed"<<endl;
#endif
    }
    int size(){
        return table.size();
    }
    uint32_t hashfunc(string s){
        uint32_t hash = 0;
        for( char c: s)
            hash = c + (hash<<6) + (hash<<16)-hash;
        return (hash%table.size());
    }


    void insert(string name,string type){
        uint64_t id = hashfunc(name);

        symbol *head=table[id];
        
        int i=0;
        if( head == nullptr ){
            head = new symbol(name,type);
            table[id] = head;
#ifdef PROMPT
            cout<<"Inserted in ScopeTable# "<<this->id<<" at position "<<id<<", "<<i<<endl;
#endif
            return ;
        }
        else if( head->getName() == name && head->getType() == type ){
#ifdef PROMPT
            cout<<"<"<<head->getName()<<","<<head->getType()<<">"<<" already exists in current ScopeTable"<<endl;
#endif
            return ;
        }
        else {
            while( head->next != nullptr ){
                if( head->next->getName() == name && head->next->getType() == type ){
#ifdef PROMPT
                    cout<<"<"<<head->getName()<<","<<head->getType()<<">"<<" already exists in current ScopeTable"<<endl;
#endif
                    return;
                }
                head = head->next;
                i++;
            }
            head->next = new symbol(name,type);
#ifdef PROMPT
            cout<<"Inserted in ScopeTable# "<<this->id<<" at position "<<id<<", "<<i+1<<endl;
#endif
        }
    } 

    symbol* lookup(string name,string type){
        uint64_t id = hashfunc(name);

        symbol *head = table[id];

        while( head != nullptr ){
            if( head->getName() == name && head->getType() == type )
                return head;
            head = head->next;
        }

        return (parent_scope==nullptr)? nullptr: parent_scope->lookup(name,type);
    }

    symbol* lookup(string name){
        uint64_t id = hashfunc(name);

        symbol *head = table[id];
        int i =0;
        while( head != nullptr ){
            if( head->getName() == name){
#ifdef PROMPT
                cout<<"Found in ScopeTable# "<<this->id<<" at position "<<id<<", "<<i<<endl;
#endif
                return head;
            }
            head = head->next;
            i++;
        }

        if( parent_scope == nullptr ){
#ifdef PROMPT
            cout<<"Not found\n";
#endif
            return nullptr ;
        }
        return parent_scope->lookup(name);
    }

    void remove(string name, string type){
        uint64_t id = hashfunc(name);

        symbol *head = table[id];

        if( head == nullptr ){
            if( parent_scope == nullptr )
                return ;
            parent_scope->remove(name,type);
            return ;
        }  
        else if( head->getName() == name && head->getType() == type ){
            table[id] = head->next;
            head->next = nullptr ;
            delete head;
            return ;
        }
        while( head->next != nullptr){
            if( head->next->getName() == name && head->next->getType() == type ){
                symbol *temp = head->next;
                head->next = head->next->next;
                temp->next = nullptr ;
                delete temp;
                return ;
            }
            head = head->next;
        }

        if( parent_scope == nullptr )
            return ;
        parent_scope->remove(name,type);
    } 

    void remove(string name){
        uint64_t id = hashfunc(name);

        symbol *head = table[id];

        int i = 0;
        if( head == nullptr ){
            if( parent_scope == nullptr ){
#ifdef PROMPT
                cout<<name<<" not found\n";
#endif
                return ;
            }            
            parent_scope->remove(name);
            return ;
        }  
        else if( head->getName() == name ){
            table[id] = head->next;
            head->next = nullptr ;
            delete head;
#ifdef PROMPT
            cout<<"Deleted Entry "<<id<<", "<<i<<" from current ScopeTable"<<endl;
#endif
            return ;
        }

        while( head->next != nullptr){
            if( head->next->getName() == name ){
                symbol *temp = head->next;
                head->next = head->next->next;
                temp->next = nullptr ;
                delete temp;
#ifdef PROMPT
                cout<<"Deleted Entry "<<id<<", "<<i+1<<" from current ScopeTable"<<endl;
#endif
                return ;
            }
            head = head->next;
            i++;
        }

        if( parent_scope == nullptr ){
#ifdef PROMPT
            cout<<name<<" not found\n";
#endif
            return;
        }
        parent_scope->remove(name);
    } 

    void print(){
        cout<<"ScopeTable # "<<id<<endl;
        for(int i=0;i<table.size();i++){
            cout<<i<<" -->";
            symbol* head = table[i];
            while( head != nullptr ){
                cout<<"  < "<<head->getName()<<" : "<<head->getType()<<" >";
                head = head->next;
            }
            cout<<endl;
        }
        cout<<endl;
    }
};


class symbol_table{
    int bucket_size ;
    vector<scope_table*> scopes;
    public:
    symbol_table(int bucket_size){
        this->bucket_size = bucket_size;
        scopes.push_back(new scope_table(bucket_size));
    }
	~symbol_table(){
		for( scope_table *scope: scopes )
			delete scope;
	}
    void enter_scope(){
        if( scopes.empty() )
            scopes.push_back(new scope_table(bucket_size));
        else {
            scope_table* current = scopes.back();
            scopes.push_back(new scope_table(bucket_size,current));
        }
    }
    void exit_scope(){
        if( scopes.empty())
            return ;
        else {
            scope_table* current = scopes.back();
            scopes.pop_back();
            delete current; 
        }
    }
    void insert(string name,string type){
        if( scopes.empty() )
            enter_scope();
        scopes.back()->insert(name,type);
    }

    void remove(string name){
        if( scopes.empty())
            return ;
        
        scopes.back()->remove(name);
    }
    symbol* lookup(string name){
        if( scopes.empty())
            throw underflow_error("empty symboltable");
        return scopes.back()->lookup(name);
    }
    void print_current_scope_table(){
        if( scopes.empty())
            throw underflow_error("empty symboltable");
        scopes.back()->print();
    }
    void print_all_scope_table(){
        if( scopes.empty())
            throw underflow_error("empty symboltable");
        for(int i=(int)scopes.size()-1;i>=0;i--)
            scopes[i]->print();
    }
};
