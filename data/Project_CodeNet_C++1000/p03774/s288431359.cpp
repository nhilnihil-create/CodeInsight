// C++ 14
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

typedef pair<int, int> P;

int main() {
  ll n, m; cin >> n >> m;
  vector<P> S(n), C(m);
  loop(i,0,n) cin >> S[i].first >> S[i].second;
  loop(i,0,m) cin >> C[i].first >> C[i].second;
  
  const int INF = 1400000000;
  vector<int> I(n);
  loop(i,0,n) {
    int min_ = INF;
    loop(j,0,m) {
      int d = abs(S[i].first - C[j].first) + abs(S[i].second - C[j].second);
      if (min_ > d) {
        I[i] = j + 1;
        min_ = d;
      }
    }
  }
  loop(i,0,n) cout << I[i] << endl;
  return 0;
}
