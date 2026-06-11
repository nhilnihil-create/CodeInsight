#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string X;
  cin >> X;
  deque<char> deq;
  for (int i = 0; i < X.length(); i++) {
    if (deq.size() == 0) {
      deq.push_back(X[i]);
    } else {
      char top = deq.back();
      if (top == 'S' && X[i] == 'T') {
        deq.pop_back();
      } else {
        deq.push_back(X[i]);
      }
    }
  }
  cout << deq.size() << endl;
  return 0;
}