#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  sort(S.begin(), S.end());
  S.erase(unique(S.begin(), S.end()), S.end());
  cout << ((N == S.size()) ? "yes" : "no") << "\n";
}