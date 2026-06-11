#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int A = S.size() - 1;
  cin >> A;
  cout << S[0] << S.size() - 2 << S[A] << endl;
}
