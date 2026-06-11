#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string O,E; cin>>O>>E;

    string ans="";
    int o=0,e=0;
    while(o<O.size() || e<E.size()){
        if(o<O.size()) ans+=O.at(o);
        if(e<E.size()) ans+=E.at(e);
        o++; e++;
    }

    cout<<ans<<endl;
}