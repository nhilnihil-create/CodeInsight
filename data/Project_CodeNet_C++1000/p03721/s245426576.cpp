#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;

int main()
{
  ll N, K;
  cin >> N >> K;
  vector<P> A(N);
  REP(i,N) cin >> A[i].first >> A[i].second;
  
  sort(ALL(A));

  ll cnt = 0;
  ll ans = 0;
  REP(i,N){
    cnt+=A[i].second;
    if(cnt>=K){
      ans=A[i].first;
      break;
    }
  }

  cout << ans << endl;
}