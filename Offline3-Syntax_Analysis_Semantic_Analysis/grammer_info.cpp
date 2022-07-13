#include <bits/stdc++.h>
#include "symbol_table.cpp"

using namespace std ;

class grammer_info {
    public :
    string text;
    string name; 
    int type;
    vector<symbol> ids;

    grammer_info(string text){
        this->text = text;
    }
    grammer_info(string name,string text){
        this->text = text;
        this->name = name ;
    }

    ~grammer_info(){
        // cout<<name<<" , deleted\n";
    }
};

