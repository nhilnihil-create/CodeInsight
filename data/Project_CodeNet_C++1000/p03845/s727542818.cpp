#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;


int main() {
  int n,m;
  cin>>n;
  vector<int> t(n);
  ll sum=0;
  rep(i,n){
    cin>>t[i];
    sum+=t[i];
  }
  cin>>m;

  rep(i,m){
    int p,x;
    cin>>p>>x;
    p--;
    ll ans=sum-t[p]+x;
    cout<<ans<<"\n";
  }


  return 0;
}
