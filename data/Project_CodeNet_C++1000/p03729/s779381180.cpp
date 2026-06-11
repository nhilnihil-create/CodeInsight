#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B, C;
  cin >> A >> B >> C;
  cout << ((A.back() == B.front() && B.back() == C.front()) ? "YES" : "NO") << "\n";
}