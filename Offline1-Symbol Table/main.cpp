#include <bits/stdc++.h>
#include "symbol_table.cpp"
using namespace std ;

#define PROMPT 1

int main(){
    int bucket_size ;
    cin>>bucket_size;
    symbol_table theSymbolTable(bucket_size);

    string cmd;
    string name;
    string type ;
    while(1){
        
        cin>>cmd;

        if( cmd == "I"){
            cin>>name>>type ;
            theSymbolTable.insert(name,type);
        }
        else if( cmd=="S"){
            theSymbolTable.enter_scope();
        }
        else if( cmd=="E")
            theSymbolTable.exit_scope();
        else if( cmd=="L"){
            cin>>name;
            theSymbolTable.lookup(name);
        }
        else if( cmd=="D"){
            cin>>name;
            theSymbolTable.remove(name);
        }
        else if( cmd == "P"){
            cin>>name;
            if( name == "A")
                theSymbolTable.print_all_scope_table();
            else theSymbolTable.print_current_scope_table();
        }
    }

}