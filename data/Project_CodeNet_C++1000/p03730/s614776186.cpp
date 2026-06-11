#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, int> PL;
constexpr int mod = 1e9 + 7;
constexpr int INF = 2e9;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
 
  for (int i = a; i <= b * a; i++) {
    if (i % a == 0) {
      if (i % b == c) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
} 