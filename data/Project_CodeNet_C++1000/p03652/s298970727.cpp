#include<iostream>
#include <cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;


int main(){
  int N, M; cin >> N >> M; int a[N][M];
  rep(i, N){
    rep(j, M){
      cin >> a[i][j]; a[i][j]--;
    }
  }
  bool check[M] = {}; int ans = inf;
  rep(k, M){
    int cnt[M] = {};
    rep(i, N){
      rep(j, M){
        if(check[a[i][j]]) continue;
        cnt[a[i][j]]++; break;
      }
    }
    int tmp = 0, maxj;
    rep(j, M){
      tmp = max(tmp, cnt[j]);
      if(tmp==cnt[j]) maxj = j;
    }
    check[maxj] = true;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}