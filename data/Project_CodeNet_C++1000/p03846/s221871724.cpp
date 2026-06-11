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
const int INF=1e18;
const int MAX=3000;

int powMOD(int x,int r){
    if(r==0)return 1;
    if(r%2==0)return powMOD(x,r/2)*powMOD(x,r/2)%MOD;
    if(r%2==1)return powMOD(x,r-1)*x%MOD;
}

signed main(){
    int N;cin>>N;
    map<int,int>memo;
    REP(i,N){
        int a;cin>>a;
        memo[a]++;
    }
    bool ok=true;
    int i=(N%2==0?1:0);
    for(auto v:memo){
        if(N%2==0){
            if(v.first!=i||v.second!=2){
                ok=false;
                break;
            }
            i+=2;
        }
        else{
            if(i==0){
                if(v.first!=0||v.second!=1){
                ok=false;
                break;
                }
                i+=2;
            }
            else{
                if(v.first!=i||v.second!=2){
                ok=false;
                break;
                }
                i+=2;
            }
        }
    }
    if(ok)cout<<powMOD(2,N/2)<<endl;
    else cout<<0<<endl;
}