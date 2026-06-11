#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;
const int MAX=3000;

signed main(){
    string A,B,C;cin>>A>>B>>C;
    if(A[A.size()-1]==B[0]&&B[B.size()-1]==C[0])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}