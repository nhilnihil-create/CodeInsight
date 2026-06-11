#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string S; cin>>S;
    string dm="dream",dmer="dreamer",es="erase",eser="eraser";

    reverse(ToEnd(S));
    reverse(ToEnd(dm));
    reverse(ToEnd(dmer));
    reverse(ToEnd(es));
    reverse(ToEnd(eser));

    while(S.find(eser)!=string::npos){
        int i=S.find(eser);
        S.erase(i,eser.size());
    }
    while(S.find(es)!=string::npos){
        int i=S.find(es);
        S.erase(i,es.size());
    }
    while(S.find(dmer)!=string::npos){
        int i=S.find(dmer);
        S.erase(i,dmer.size());
    }
    while(S.find(dm)!=string::npos){
        int i=S.find(dm);
        S.erase(i,dm.size());
    }

    string ans="YES";
    if(S.size()) ans="NO";
    cout<<ans<<endl;
}