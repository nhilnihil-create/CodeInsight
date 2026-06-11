#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,0,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back

signed main(){
    map<int,int>memo;
    REP(i,3){
        int a;cin>>a;
        memo[a]++;
    }
    int ans=0;
    for(auto v:memo)ans++;
    cout<<ans<<endl;
}
