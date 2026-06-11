#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  if (A.size() < B.size()) while (A.size() < B.size()) A = "0" + A;
  if (B.size() < A.size()) while (B.size() < A.size()) B = "0" + B;
  cout << ((A > B) ? "GREATER" : (A < B) ? "LESS" : "EQUAL") << "\n";
}