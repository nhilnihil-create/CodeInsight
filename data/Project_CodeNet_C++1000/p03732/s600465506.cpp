#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>//pair
#include<cmath>//abs,sqrt
#include<cstring>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int INF=1e+9;
const ll INFLL=1e+17;
ll dp[110][310][110];
ll n,W;
ll w[101],v[101];
bool f[110][310][110];
ll rec(ll i,ll j,ll k){
  ll res;
  if(f[i][j][k]) return dp[i][j][k];
  if(i==0||k==0) return 0;
  if(j-w[i-1]<0){
    res=rec(i-1,j,k);
  }
  else{
    res=max(rec(i-1,j,k),rec(i-1,j-w[i-1],k-1)+v[i-1]);
  }
  f[i][j][k]=true;
  return dp[i][j][k]=res;
}

int main(){
  cin>>n>>W;
  rep(i,n){
    cin>>w[i]>>v[i];
  }
  ll w0=w[0];
  rep(i,n){
    w[i]-=w0;
  }
  ll m=3*n;
  ll res=0;
  rep(k,n+1){
    fill(dp,0);
    fill(f,0);
    if(W<k*w0) continue;
    ll ww=W-k*w0;
    if(ww>m) ww=m;
    //  prin(rec(n,ww,k));
    res=max(res,rec(n,ww,k));
  }
  prin(res);
  
  

  
  
  

  
  
  

  return 0;
}
