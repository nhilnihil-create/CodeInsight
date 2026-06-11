#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,k;
  cin >> n >> k;
  ll a[n];
  ll psum[n+1];
  ll msum[n+1];
  ll ans=-1LL*1e15;
  psum[0]=0;msum[0]=0;
  rep(i,n){
    cin >> a[i];
    psum[i+1]=psum[i];
    msum[i+1]=msum[i];
    if(a[i]>0){
      psum[i+1] +=a[i];      
    }
    else msum[i+1]+=a[i];

  }
  
  rep(i,n-k+1){
    ll t=psum[n];
    //    cout << t << endl;
    ans=max(ans,t+msum[i+k]-msum[i]);
    ans=max(ans,t-psum[i+k]+psum[i]);
  }

  
  cout << ans << endl;
  return 0;
    

}
