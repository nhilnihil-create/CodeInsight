#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; cin >> N;
  int x[N]; rep(i,N) cin >> x[i];

  int pos = 0;
  ll result = 1;
  rep(i,N) {
    while (2*(pos-i)<x[pos]&&pos<N-1) pos++;
    // cout << (pos+1)-i << endl;
    result *= (pos+1)-i; result %= MOD;
  }
  cout << result << endl;
  return 0;
}