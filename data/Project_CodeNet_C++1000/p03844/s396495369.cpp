#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int a, b;
  char op;
  cin >> a >> op >> b;
  if (op == '+') {
    cout << a + b << endl;
    return 0;
  }
  cout << a - b << endl;
  return 0;
}