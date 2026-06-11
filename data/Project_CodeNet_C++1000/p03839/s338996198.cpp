#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<(n); i++)
#define int long long
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 1000000000000000000
using namespace std;
signed main(void){
    int n,k;cin>>n>>k;
    vector<int>V(n);rep(i,n)cin>>V[i];
    int Minus[n+1],Plus[n+1];Minus[0]=Plus[0]=0;
    rep(i,n){
        Plus[i+1]=Plus[i]+max((int)0,V[i]);
        Minus[i+1]=Minus[i]+min((int)0,V[i]);
    }
    int sum=Plus[n];int ans=-INF;
    int com0,com1;
    rep(i,n-k+1){
        com0=sum-(Plus[i+k]-Plus[i]);
        com1=sum+(Minus[i+k]-Minus[i]);
        ans=max(ans,max(com0,com1));
    }
    cout<<ans<<endl;
}