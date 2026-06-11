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

int DP[45][500][500];

int main() {
  int N, Ma, Mb;
  cin>>N>>Ma>>Mb;
  int A[N], B[N], C[N];
  for(int i=0;i<N;++i) cin>>A[i]>>B[i]>>C[i];
  for(int i=0;i<45;++i) {
    for(int j=0;j<500;++j) {
      for(int k=0;k<500;++k) {
        DP[i][j][k] = inf;
      }
    }
  }
  DP[0][0][0] = 0;
  DP[0][A[0]][B[0]] = C[0];
  for(int i=0;i<N-1;++i) {
    for(int j=0;j<500;++j) {
      for(int k=0;k<500;++k) {
        if(DP[i][j][k]==inf) continue;
        DP[i+1][j][k] = min(DP[i+1][j][k], DP[i][j][k]);
        DP[i+1][j+A[i+1]][k+B[i+1]] = min(DP[i+1][j+A[i+1]][k+B[i+1]], DP[i][j][k]+C[i+1]);
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

