#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string X;
  cin >> X;
  stack<char> s;
  s.push(X[0]);
  for (int i = 1; i < X.size(); i++) {
    if (X[i] == 'S')
      s.push(X[i]);
    else {
      if (s.size() > 0 && s.top() == 'S') {
        s.pop();
      } else {
        s.push(X[i]);
      }
    }
  }
  cout << s.size() << endl;
}