#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define _GLIBCXX_DEBUG
const int INF=1e18;

signed main(){
  	string S;cin>>S;
    bool ok=false;
    REP(i,2){
        int d=S[i]-'0';
        if(d==9)ok=true;
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
