#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,0,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;

signed main(){
    int N;cin>>N;
    map<int,int>memo;
    for(int i=2;i<=N;i++){
        int C=i;
        for(int j=2;j<=sqrt(C);j++){
            while(C%j==0){
                memo[j]++;
                C/=j;
            }
        }
        if(C!=1)memo[C]++;
    }
    int ans=1;
    for(auto v:memo){
        ans*=(v.second+1);
        ans%=MOD;
    }
    cout<<ans<<endl;
}