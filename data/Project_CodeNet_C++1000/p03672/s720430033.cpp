#include <bits/stdc++.h>
using namespace std;

bool f(string S) {
  int N = S.size();
  return S.substr(0, N / 2) == S.substr(N / 2);
}

int main() {
  string S;
  cin >> S;
  S.pop_back();
  while (!f(S)) S.pop_back();
  cout << S.size() << "\n";
}