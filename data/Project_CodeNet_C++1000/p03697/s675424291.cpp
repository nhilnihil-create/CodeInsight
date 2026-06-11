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
  if (A+B >= 10) {
    cout << "error" << endl;
  } else {
    cout << A+B << endl;
  }
  return 0;
}