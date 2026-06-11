#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int A,B;
  cin >> A >> B;
  if (A == 1) A = 14;
  if (B == 1) B = 14;
  if (A < B) {
    cout << "Bob" << endl;
  } else if (A > B) {
    cout << "Alice" << endl;
  } else {
    cout << "Draw" << endl;
  }
  return 0;
}