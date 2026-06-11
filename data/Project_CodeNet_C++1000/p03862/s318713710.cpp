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

int main() {
  ll N, X;
  cin>>N>>X;
  ll a[N];
  for(int i=0;i<N;++i) cin>>a[i];
  ll ans = 0;
  ll zero = 0;
  for(int i=0;i<N-1;++i) {
    if(a[i]+a[i+1]>X) {
      if(a[i]>X) {
        ans += a[i+1];
        a[i+1] = 0;
        ans += a[i] - X;
        a[i] = X;
      }
      else {
        ans += a[i]+a[i+1]-X;
        a[i+1] -= a[i]+a[i+1]-X;
      }
    }
  }
  cout<<ans<<endl;
}

