#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll a[100010];
ll sum_all[100010],sum_plus[100010];

int main(){
  int n,k;
  cin>>n>>k;
  rep(i,n)cin>>a[i];
  rep(i,n){
    sum_all[i+1]=sum_all[i]+a[i];
    sum_plus[i+1]=sum_plus[i]+(a[i]>=0?a[i]:0);
  }
  ll ans=0;
  //白
  for(int i=1; i<=n-k+1; ++i){
    ans=max(ans,(sum_all[i+k-1]-sum_all[i-1])+((sum_plus[n]-sum_plus[0])-(sum_plus[i+k-1]-sum_plus[i-1])));
  }
  //黒
  for(int i=1; i<=n-k+1; ++i){
    ans=max(ans,((sum_plus[n]-sum_plus[0])-(sum_plus[i+k-1]-sum_plus[i-1])));
  }
  cout<<ans<<endl;
}