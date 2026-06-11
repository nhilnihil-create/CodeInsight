#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string A, B;
  cin >> A >> B;

  if (A.size() > B.size())
    cout << "GREATER" << endl;
  else if (A.size() < B.size())
    cout << "LESS" << endl;
  else {
    if (A > B)
      cout << "GREATER" << endl;
    else if (A < B)
      cout << "LESS" << endl;
    else if (A == B)
      cout << "EQUAL" << endl;
  }
  return 0;
}