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

int DP[50][500][500];

int main() {
  for(int i=0;i<50;++i) {
    for(int j=0;j<500;++j) {
      for(int k=0;k<500;++k) {
        DP[i][j][k] = inf;
      }
    }
  }
  int N, Ma, Mb;
  cin>>N>>Ma>>Mb;
  int a[N], b[N], c[N];
  for(int i=0;i<N;++i) cin>>a[i]>>b[i]>>c[i];
  DP[0][0][0] = 0;
  DP[0][a[0]][b[0]] = c[0];
  for(int i=0;i<N-1;++i) {
    for(int j=0;j<500;++j) {
      for(int k=0;k<500;++k) {
        DP[i+1][j][k] = min(DP[i+1][j][k], DP[i][j][k]);
        if(j+a[i+1]<500 && k+b[i+1]<500) {
          DP[i+1][j+a[i+1]][k+b[i+1]] = min(DP[i+1][j+a[i+1]][k+b[i+1]], DP[i][j][k]+c[i+1]);
        }
      }
    }
  }
  int ans = inf;
  for(int i=1;i*Ma<500 && i*Mb<500;++i) {
    ans = min(ans, DP[N-1][i*Ma][i*Mb]);
  }
  if(ans==inf) cout<<-1<<endl;
  else cout<<ans<<endl;
}

