// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
#define chmax(x,y) (x = max(x, y))
//  cout.precision(15); cout << fixed;

int main() {
  int h, w; cin >> h >> w;
  vector<string> S(h);
  loop(i,0,h) cin >> S[i];
  loop(i,0,h) {
    loop(j,0,2) cout << S[i] << endl;
  }
  return 0;
}
