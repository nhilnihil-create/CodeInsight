#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    map<char,int> dict;
    string w;
    cin>>w;
    size_t l=w.length();
    rep(i,l){
        dict[w[i]]++;
    }
    bool flag=true;
    for(auto iter=dict.begin();iter!=dict.end();iter++){
        if(iter->second%2==1) flag=false;
    }
    if(flag) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    return 0;
}