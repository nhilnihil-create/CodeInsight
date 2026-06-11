#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main(){
  int N, T;
  cin >> N >> T;

  int start = 0;
  int stop = 0;
  int sum = 0;
  rep(i, N){
    int t;
    cin >> t;
    if(t > stop){
      sum += stop - start;
      start = t;
    }
    stop = t + T;
  }
  sum += stop -start;

  cout << sum << endl;

  return 0;
}
