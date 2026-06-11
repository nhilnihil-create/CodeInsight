#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  string ans = "No";

  if ((a + b) == c || (a + c) == b || (b + c) == a) {
    ans = "Yes";
  }

  cout << ans << endl;

  return 0;
}