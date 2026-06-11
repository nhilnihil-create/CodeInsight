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

  ll ok = N;  // compare(ok) is always true
  ll ng = 0;    // compare(ng) is always false

  auto compare = [&](ll X) {
    // X = max in S
    ll Y = N - X; // 和で作るべき値

    // X 未満の数字を使って、Y以上を作ることが出来るか
    ll x = X;
    return x * (x - 1) / 2 >= Y;

    // X 未満の数字を使って、ちょうどYを作ることが出来るか

  };
  
  while(abs(ok-ng) > 1) { // ng極限の隣がokとなるまで
    ll mid = (ok + ng) / 2LL;
    (compare(mid) ? ok : ng) = mid;
  }

  ll sum = 0;
  for(int i = min(ok - 1, N - ok); i>=1; i--) {
    if(sum == N - ok) break;
    if(sum + i > N - ok) continue;
    printf("%d\n", i);
    sum += i;
  }

  cout << ok << endl;

  
  return 0;
}