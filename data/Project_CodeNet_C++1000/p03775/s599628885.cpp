#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int keta(ll a) {
  ll tmp = 1e10;
  ll ans;
  for(int i=11;i>0;--i) {
    if(a/tmp>0) {
      ans = i;
      break;
    }
    tmp /= 10;
  }
  return ans;
}

int main() {
  ll N;
  cin>>N;
  int ans = inf;
  for(ll i=1;i*i<=N;++i) {
    if(N%i==0) {
      ans = min(ans, max(keta(i), keta(N/i)));
    }
  }
  cout<<ans<<endl;
}

