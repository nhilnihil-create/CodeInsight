#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    string o,e;
    cin>>o>>e;
    
    rep(i,e.length()){
        cout<<o[i]<<e[i];
    }
    if(o.length()>e.length()) cout<<o.back()<<"\n";
    return 0;
}