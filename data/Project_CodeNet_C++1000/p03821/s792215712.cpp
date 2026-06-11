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
  ll N;
  cin >> N;

  vector<P> A(N);
  REP(i,N) cin >> A[i].first >> A[i].second;
  
  ll ans = 0;
  REPR(i,N-1){
    if((A[i].first+ans)%A[i].second!=0){
      ans+=(((A[i].first+ans)/A[i].second)+1)*A[i].second-(A[i].first+ans);
    }
  }

  cout << ans << endl;
}