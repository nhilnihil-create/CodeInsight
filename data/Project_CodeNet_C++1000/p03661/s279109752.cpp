#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >=0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

typedef long long ll;
#define INF 1e9

int main(){
  int N;
  ll mini = 1e16;
  cin >> N;
  vector<ll> a(N), sum(N+1);
  sum[0] = 0;
  REP(i, N){
    cin >> a[i];
    sum[i+1] = sum[i] + a[i];
  }

  FOR(i, 1, N){
    ll x = sum[i];
    ll y = sum[N] - x;
    mini = min(mini, abs(x-y));
  }
  cout << mini << endl;
  return 0;
}