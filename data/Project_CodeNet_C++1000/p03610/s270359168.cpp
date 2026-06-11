#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int MOD=1e9+7;
const int INF=1e20;

signed main(){
    string S;cin>>S;
    REP(i,S.size()){
        if(i%2==0)cout<<S[i];
    }
    cout<<endl;
}