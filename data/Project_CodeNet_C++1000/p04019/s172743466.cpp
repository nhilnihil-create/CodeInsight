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
    string T;cin>>T;
    int N,S,E,W;
    N=S=E=W=0;
    REP(i,T.size()){
        if(T[i]=='N')N++;
        if(T[i]=='S')S++;
        if(T[i]=='E')E++;
        if(T[i]=='W')W++;
    }
    if((N>0&&S==0)||(S>0&&N==0)||(E>0&&W==0)||(W>0&&E==0))cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}