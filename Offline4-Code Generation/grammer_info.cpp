#include <bits/stdc++.h>
#include "symbol_table.cpp"

using namespace std ;

class grammer_info {
    public :
    string text;
    string name; 
    string type;
    bool array = 0;
    vector<param> ids;
    grammer_info(string text){
        this->text = text;
    }
    grammer_info(string name,string text){
        this->text = text;
        this->name = name ;
    }
    grammer_info(const grammer_info& rhs){
        this->text = rhs.text;
        this->name = rhs.name;
        this->type = rhs.type;
        this->array = rhs.array;
        this->ids = rhs.ids;
    }
    ~grammer_info(){
        // cout<<name<<" , deleted\n";
    }
};

