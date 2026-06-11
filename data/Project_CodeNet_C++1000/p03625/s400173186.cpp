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
 
signed main(){
    int N;cin>>N;
    map<int,int>memo;
    REP(i,N){
        int a;cin>>a;
        memo[-a]++;
    }
    int ans=0;
    bool check=false;
    for(auto v:memo){
        if(v.second>=4&&!check){
            ans=v.first*v.first;
        }
        else{
            if(v.second>=2){
                if(!check){
                  	ans=v.first;
                  	check=true;
                }
                else ans*=v.first;
            }
        }
        if(ans>0)break;
    }
    if(ans<=0)ans=0;
    cout<<ans<<endl;
}
