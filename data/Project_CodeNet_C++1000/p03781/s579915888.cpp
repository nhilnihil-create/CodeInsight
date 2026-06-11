#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll X;
ll A, R;

int main() {
  cin >> X;
  while (A < X) {
    ++R;
    A += R;
  }
  cout << R << endl;
  return 0;
}
