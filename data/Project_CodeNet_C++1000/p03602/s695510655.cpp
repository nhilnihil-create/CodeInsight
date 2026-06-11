#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<utility>
#include<memory>
#include<cmath>
#include<stack>
#include<tuple>
#include<numeric>
#include<cassert>

#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define pb push_back
#define DEBUG false

using namespace std;

using ll = long long;
using P = pair<int,int>;

const int mod=1e9+7,INF=1<<30;
const double EPS=1e-12,PI=3.1415926535897932384626;
const ll LINF=1LL<<60;
const int MAX_N=302;
const ll lmod = 1e9+7;

ll d[MAX_N][MAX_N],a[MAX_N][MAX_N];

int main(){
  int N;
  cin >> N ;
  rep(i,N) rep(j,N){
    scanf("%lld",&d[i][j]);
    a[i][j] = d[i][j];
  }
  rep(i,N) rep(j,N) rep(k,N){
    a[j][i] = a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
  }
  rep(i,N) rep(j,N){
    if(d[i][j]!=a[i][j]){
      cout << "-1" << endl;
      return 0;
    }
  }
  rep(i,N-1) REP(j,i+1,N) rep(k,N){
    if(k==i || k==j) continue;
    // cout << i << "," << j << "," << k << endl;
    if(a[i][j]==a[i][k]+a[k][j]){
      d[i][j] = 0;
    }
  }
  ll ans = 0;
  rep(i,N-1) REP(j,i+1,N) ans += d[i][j];
  cout << ans << endl;
  return 0;
}