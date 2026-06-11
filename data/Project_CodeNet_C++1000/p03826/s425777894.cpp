#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  cout << (A*B >= C*D ? A*B : C*D);
}