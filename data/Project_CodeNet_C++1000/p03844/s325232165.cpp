#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int a, b;
char op;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> a >> op >> b;
  if (op == '+') {
    cout << a + b << endl;
  } else {
    cout << a - b << endl;
  }

  return 0;
}
