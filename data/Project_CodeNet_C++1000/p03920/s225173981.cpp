#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

int main() {

  ll N; cin >> N;

  ll ok = N;    // compare(ok) is always true
  ll ng = 0;    // compare(ng) is always false
  
  while(abs(ok-ng) > 1) {
    ll mid = (ok + ng) / 2LL;
    (mid * (mid - 1) / 2 >= N - mid ? ok : ng) = mid;
  }

  ll sum = 0;
  for(int i = ok - 1; i>=1; i--) {
    if(sum + i > N - ok) continue;
    printf("%d\n", i);
    sum += i;
  }

  cout << ok << endl;
  
  return 0;
}