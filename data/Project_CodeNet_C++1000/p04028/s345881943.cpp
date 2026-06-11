#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
ll int MOD=1e9+7;
#define N 6000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

ll int poww(ll int a,ll int b){
    ll int ans=1,temp=a;
    while(b){
        
        if(b%2) ans=(temp*ans)%MOD;
        b>>=1;
      temp=(temp*temp)%MOD;

    }
    return ans;
}
ll int n;

ll int dp[N][N]={};
ll int calc(ll int a,ll int b){
    if(a<b) return 0;
    if(dp[a][b]) return dp[a][b];
    if(a==0){
        if(b==0) return 1;
        else return 0;
    }
    if(b==0){
        return dp[a][b]=(calc(a-1,1)+calc(a-1,0))%MOD;
    }
    return dp[a][b]=(calc(a-1,b+1)+calc(a-1,b-1)*2)%MOD;
}
main(){
    string s;
    cin>>n>>s;
    ll int t=s.size();
    ll int inv=poww(poww(2,t),MOD-2);
    cout<<calc(n,t)*inv%MOD;

    
    

    return 0;
}