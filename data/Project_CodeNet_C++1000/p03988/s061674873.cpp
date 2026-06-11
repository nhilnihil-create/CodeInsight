#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000010
#define EPS 1e-9
#define fst first
#define scd second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  int a[n];
  rep(i,n) cin>>a[i];
  sort(a,a+n);
  int mx=a[n-1];
  int mn=mx/2;
  int mp[mn+1];
  //cout<<mx<<" "<<(mx+1)/2<<endl;
  rep(i,mn+1){
    mp[i]=-1;
  }
  if(mx%2==0){
    mp[mn]=0;
  }
  rep(i,n){
    if(a[i]<((mx+1)/2) || a[i]>mx){
      cout<<"Impossible"<<endl;
      return 0;
    }else{
      mp[mx-a[i]]++;
    }
  }
  rep(i,mn+1){
    if(mp[mn]!=1 || mp[i]<=0 ){
      cout<<"Impossible"<<endl;
      return 0;
    }
  }
  cout<<"Possible"<<endl;
  

  return 0;
}
