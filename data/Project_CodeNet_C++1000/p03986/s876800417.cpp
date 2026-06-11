#include <bits/stdc++.h>
using namespace std;

int main() {
  char C;
  stack<char> S;
  while (cin >> C) {
    if (S.empty()) S.push(C);
    else if (C == 'T' && S.top() == 'S') S.pop();
    else S.push(C);
  }
  cout << S.size() << "\n";
}