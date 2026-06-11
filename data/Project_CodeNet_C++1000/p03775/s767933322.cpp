#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
using pll = pair<long,long>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back

int main() {
  ll n; cin>>n;
  int res=100;
  for(ll i=1;i*i<=n;i++) {
    if(n%i==0) res=min(res,(int)to_string(n/i).size());
  }
  cout<<res<<endl;
}
