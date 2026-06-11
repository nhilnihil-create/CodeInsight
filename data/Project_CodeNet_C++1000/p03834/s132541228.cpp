#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  S = regex_replace(S, regex(","), " ");
  cout << S << "\n";
}