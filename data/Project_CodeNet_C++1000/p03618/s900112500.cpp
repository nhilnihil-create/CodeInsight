#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(ll i = (m); i < (n); ++i)

#define INF 1e9

int main(){
  string A;
  cin >> A;
  vector<int> cnt(26, 0);
  REP(i, A.size()){
    cnt[A[i] - 'a']++;
  }
  ll ans = (ll)A.size()*(A.size()+1)/2;
  REP(i, 26){
    ans -= (ll)cnt[i] * (cnt[i]+1)/2;
  }
  cout << ans+1 << endl;

  return 0;
}
