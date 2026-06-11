//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
int main(){
  int n;
  ll l;
  cin>>n>>l;
  vl a(n);
  rep(i,n)cin>>a[i];
  bool cant=true;
  int ans;
  rep(i,n-1){
    if(a[i]+a[i+1]>=l){
      ans=i;
      cant=false;
    }
  }
  if(cant){
    cout<<"Impossible"<<endl;
    return 0;
  }
  else cout<<"Possible"<<endl;
  ans++;
  for(int i=n-1;i>ans;i--)cout<<i<<endl;
  for(int i=1;i<ans;i++)cout<<i<<endl;
  cout<<ans<<endl;
}