#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    char a=s[0], b=s[1];
    bool ok=true;
    for(int i=2; i<s.size(); i++){
        if(s[i]!=a && s[i]!=b) ok=false;
    }
    if(ok==false){
        if(s.size()%2==1){
            if(s[0]==s[s.size()-1]){
                cout<<"Second"; return 0;
            }
            else{
                cout<<"First"; return 0;
            }
        }
        else{
            if(s[0]==s[s.size()-1]){
                cout<<"First"; return 0;
            }
            else{
                cout<<"Second"; return 0;
            }
        }
    }
    else{
        cout<<"Second"; return 0;
    }

    return 0;
}