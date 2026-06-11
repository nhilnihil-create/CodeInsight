#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int h, w, ch = 0, cw = 0;
  string s;
  cin >> h >> w;
  while (true) {
    cin >> s;
    if (s == "snuke") {
      cout << (char)(cw + 'A') << ch + 1 << endl;
      return 0;
    }
    if (++cw >= w) {
      cw = 0;
      ch++;
    }
  }
  return 0;
}