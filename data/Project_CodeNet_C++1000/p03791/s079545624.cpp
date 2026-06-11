#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)

typedef long long ll;

const ll MOD = 1000000007;

int main(){
  int N;
  cin >> N;
  vector<int> x(N);
  REP(i,N) cin >> x[i];

  stack<int> st;
  ll res = 1LL;
  REP(i,N) {
    st.push(x[i]);
    if(st.top() < 2 * st.size() - 1) {
      res = (res * (ll)st.size()) % MOD;
      st.pop();
    }
  }
  REP(i,st.size()) res = (res * (ll)(i + 1)) % MOD;
  cout << res << endl;
  return 0;
}

