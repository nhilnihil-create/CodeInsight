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
    int A,B,C,D;cin>>A>>B>>C>>D;
    string ans="";
    REP(i,C-A)ans+='R';
    REP(i,D-B)ans+='U';
    REP(i,C-A)ans+='L';
    REP(i,D-B)ans+='D';
    ans+='D';
    REP(i,C-A+1)ans+='R';
    REP(i,D-B+1)ans+='U';
    ans+='L';
    ans+='U';
    REP(i,C-A+1)ans+='L';
    REP(i,D-B+1)ans+='D';
    ans+='R';
    cout<<ans<<endl;
}