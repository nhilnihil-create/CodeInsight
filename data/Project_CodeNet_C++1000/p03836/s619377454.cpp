#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
  int sx, sy, tx, ty;
  cin>>sx>>sy>>tx>>ty;
  string ans = "";
  for(int i=0;i<ty-sy;++i) ans += 'U';
  for(int i=0;i<tx-sx;++i) ans += 'R';
  for(int i=0;i<ty-sy;++i) ans += 'D';
  for(int i=0;i<tx-sx;++i) ans += 'L';
  ans += 'L';
  for(int i=0;i<=ty-sy;++i) ans += 'U';
  for(int i=0;i<=tx-sx;++i) ans += 'R';
  ans += 'D';
  ans += 'R';
  for(int i=0;i<=ty-sy;++i) ans += 'D';
  for(int i=0;i<=tx-sx;++i) ans += 'L';
  ans += 'U';
  cout<<ans<<endl;
}

