#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int M = 1e9 + 7;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};


int main() {
  int n;
  cin >> n;
  int m = 2;
  int s = 0;
  rep(i,n) {
    int a = 0;
    cin >> a;
    s += a%2;
  }
  if (s%2) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}
