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

int N;
ll L;
int doub[20][100005];
vector<ll> x(100005, big);

void prepare() {
  int index;
  for(int i=0;i<N;++i) {
    index = upper_bound(x.begin(), x.end(), x[i]+L) - x.begin() - 1;
    doub[0][i] = index;
  }
  for(int i=1;i<20;++i) {
    for(int j=0;j<N;++j) {
      doub[i][j] = doub[i-1][doub[i-1][j]];
    }
  }
}

int solve(int a, int b) {
  int ans = 0;
  int tmp;
  int two;
  while(a<b) {
    tmp = 0;
    two = 1;
    while(doub[tmp+1][a]<b) {
      two *= 2;
      tmp++;
    }
    ans += two;
    a = doub[tmp][a];
  }
  return ans;
}

int main() {
  cin>>N;
  for(int i=0;i<N;++i) cin>>x[i];
  cin>>L;
  prepare();
  int Q;
  cin>>Q;
  int a, b;
  int ans[Q];
  for(int i=0;i<Q;++i) {
    cin>>a>>b;
    a--;
    b--;
    if(a>b) swap(a, b);
    ans[i] = solve(a, b);
  }
  for(int i=0;i<Q;++i) cout<<ans[i]<<endl;
}

