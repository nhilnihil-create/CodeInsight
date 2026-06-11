#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main(){
  ll N, K; cin >> N >> K;
  vector<ll> a(N);
  REP(i,N) cin >> a[i];
  sort(ALL(a));
  ll ng = -1, ok = N, m;

  auto is_need = [&]{
    //m番目以外の要素の総和TをK-a[m]<=T<=K-1とできるか？
    //dp[i][j]: i番目まで見て和をjにできるか？
    vector<vector<bool>> dp(N+1, vector<bool>(K,false));
    dp[0][0] = true;
    REP(i,N){
      REP(j,K){
        dp[i+1][j] = dp[i+1][j] || dp[i][j];
        if(i != m && dp[i][j] && j+a[i] <= K-1){
          dp[i+1][j+a[i]] = true;
        }
      }
    }
    FOR(j,max(K-a[m],0LL),K){
      if(dp[N][j]) return true;
    }
    
    return false;
  };
  
  while(ng+1!=ok){
    m = (ok+ng)/2;
    //a[m]は必要か？判定する
    if(is_need())
      ok = m;
    else
      ng = m;
  }
  cout << ng + 1 << endl;
}