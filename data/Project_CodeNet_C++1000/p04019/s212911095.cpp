#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    bool north=false;
    bool south=false;
    bool east=false;
    bool west=false;

    bool judge=true;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='N'){
            north=true;
        }
        if(s[i]=='S'){
            south=true;
        }
        if(s[i]=='E'){
            east=true;
        }
        if(s[i]=='W'){
            west=true;
        }
    }

    if((north&&south==false)||(north==false&&south)){
        judge=false;
    }else if((east&&west==false)||(east==false&&west)){
        judge=false;
    }

    cout<<(judge ? "Yes" : "No")<<endl;
}