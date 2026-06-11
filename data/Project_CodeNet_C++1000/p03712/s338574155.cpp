// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

typedef pair<ll, ll> P;

int main() {
  int h, w; cin >> h >> w;
  vector<string> S(h);
  loop(i,0,h) cin >> S[i];
  loop(j,0,w+2) cout << '#'; cout << endl;
  loop(i,0,h) {
    cout << '#' << S[i] << '#' << endl;
  }
  loop(j,0,w+2) cout << '#'; cout << endl;
  return 0;
}
