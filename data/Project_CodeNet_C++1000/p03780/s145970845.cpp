#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int n,k,A[5001];
ll ok,ng,dp[5010][5010];
int solve(int x){
    rep(i,n) fill(dp[i],dp[i]+k+1,0);
    dp[0][0]=1;
    rep(I,n)rep(j,k+1){
        if(I==x) continue;
        int i=I-(I>x);
        dp[i+1][j]=dp[i][j]|dp[i+1][j];
        if(j+A[I]>k) continue;
        if(dp[i][j]) dp[i+1][j+A[I]]=1;
    }
    int z=1;
    for(int i=max(0,k-A[x]);i<k;i++) if(dp[n-1][i]) z=0;
    return z;
}
ll search(){
    ok=-1,ng=n;
    while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        if(solve(mid)) ok=mid;
        else ng=mid;
    }
    return ok;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    rep(i,n) cin>>A[i];
    sort(A,A+n);
    cout<<search()+1<<"\n";
}