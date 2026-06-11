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
  int x, y;
  bool aru[N];
  for(int i=0;i<N;++i) aru[i] = false;
  aru[0] = true;
  int num[N];
  for(int i=0;i<N;++i) num[i] = 1;
  for(int i=0;i<M;++i) {
    cin>>x>>y;
    x--;
    y--;
    if(aru[x]) aru[y] = true;
    if(aru[x] && num[x]==1) aru[x] = false;
    num[x]--;
    num[y]++;
  }
  int ans = 0;
  for(int i=0;i<N;++i) {
    if(aru[i]) ans++;
  }
  cout<<ans<<endl;
}

