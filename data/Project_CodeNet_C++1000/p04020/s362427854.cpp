#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int n;
  cin>>n;
  vector<int> a(n+1);
  rep(i,n) cin>>a[i];
  ll ans=0;
  bool odd=0;
  rep(i,n){
    if(a[i]%2!=0 && a[i+1]!=0) a[i+1]++;
    ans+=a[i]/2;
  }
  cout<<ans<<endl;
}
