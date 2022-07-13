#include <bits/stdc++.h>
using namespace std ;

class grammer_info {
    struct identifier {
        string name ;
        string type ;
    };
    public :
    string text;
    string name; 
    int type;
    vector<identifier> ids;

    grammer_info(string text){
        this->text = text;
    }
    grammer_info(string name,string text){
        this->text = text;
        this->name = name ;
    }

    ~grammer_info(){
        cout<<name<<" , deleted\n";
    }
};

