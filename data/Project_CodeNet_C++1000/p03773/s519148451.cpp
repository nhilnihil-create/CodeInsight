#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
const ll Mod = 1000000007;
int main() {
  int A,B;
  cin >> A >> B;
  int ans = (A + B) % 24;
  cout << ans << endl;
  return 0;
}