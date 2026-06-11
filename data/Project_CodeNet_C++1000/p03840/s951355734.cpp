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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll a, b, c, d, e, f, g;
  cin>>a>>b>>c>>d>>e>>f>>g;
  ll ans = 0;
  int num;
  num = a%2 + d%2 + e%2;
  if(num>=2 && a>=1 && d>=1 && e>=1) {
    ans += 3;
    a--;
    d--;
    e--;
  }
  ans += 2*(a/2);
  a %= 2;
  ans += b;
  b = 0;
  ans += 2*(d/2);
  d %= 2;
  ans += 2*(e/2);
  e %= 2;
  if(a==1 && d==1 && e==1) {
    ans += 3;
    a = 0;
    d = 0;
    e = 0;
  }
  cout<<ans<<endl;
}

