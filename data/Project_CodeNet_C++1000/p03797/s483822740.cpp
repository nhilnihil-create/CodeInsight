#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
 
signed main(){
    int N,M;
    cin>>N>>M;
    if(N*2==M) cout <<N<<endl;
    if(N*2>M) cout<<M/2<<endl;
    if(N*2<M) cout<<N+(M-2*N)/4<<endl;
}