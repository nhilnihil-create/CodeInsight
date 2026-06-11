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
  int N, M;
  cin>>N>>M;
  int a[N], b[N];
  for(int i=0;i<N;++i) {
    cin>>a[i]>>b[i];
  }
  int ans[N];
  int c[M], d[M];
  int tmp;
  for(int i=0;i<M;++i) cin>>c[i]>>d[i];
  for(int i=0;i<N;++i) {
    tmp = inf;
    for(int j=0;j<M;++j) {
      tmp = min(tmp, abs(a[i]-c[j])+abs(b[i]-d[j]));
    }
    for(int j=0;j<M;++j) {
      if(tmp==abs(a[i]-c[j])+abs(b[i]-d[j])) {
        ans[i] = j+1;
        break;
      }
    }
  }
  for(int i=0;i<N;++i)cout<<ans[i]<<endl;
}

