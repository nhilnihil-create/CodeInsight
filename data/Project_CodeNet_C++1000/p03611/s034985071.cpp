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
  int N;
  cin>>N;
  int tmp;
  map<int, int> amap;
  for(int i=0;i<N;++i) {
    cin>>tmp;
    amap[tmp-1]++;
    amap[tmp]++;
    amap[tmp+1]++;
  }
  int ans = 0;
  for(int i=-1;i<100005;++i) ans = max(ans, amap[i]);
  cout<<ans<<endl;
}

