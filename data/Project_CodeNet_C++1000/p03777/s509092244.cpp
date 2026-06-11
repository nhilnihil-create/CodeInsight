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
  char a, b;
  cin >> a >> b;

  if(a == 'H' && b == 'H') cout << "H" << endl;
  else if(a == 'H' && b == 'D') cout << "D" << endl;
  else if(a == 'D' && b == 'H') cout << "D" << endl;
  else if(a == 'D' && b == 'D') cout << "H" << endl;

  return 0;
}
