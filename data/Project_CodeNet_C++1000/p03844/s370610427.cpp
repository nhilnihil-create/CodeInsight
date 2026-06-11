#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  char op;
  cin >> a >> op >> b;
  int answer = 0;
  if (op == '+') {
    answer  = a + b;
  } else {
    answer = a - b;
  }
  cout << answer << endl;
}