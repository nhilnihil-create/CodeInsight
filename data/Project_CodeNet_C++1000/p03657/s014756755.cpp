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
  if (A % 3 != 0 && B % 3 != 0 && (A + B) % 3 != 0) {
    cout << "Impossible" << endl;
  } else {
    cout << "Possible" << endl;
  }
  return 0;
}