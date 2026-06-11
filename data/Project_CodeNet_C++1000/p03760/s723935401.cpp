#include <bits/stdc++.h>
using namespace std;

int main(){
    string o,e;
    cin>>o>>e;

    string password;

    for(int i=0; i<o.size(); i++){
        password.push_back(o[i]);
        
        if(e.size()==i){
            continue;
        }

        password.push_back(e[i]);
    }

    cout<<password<<endl;
}