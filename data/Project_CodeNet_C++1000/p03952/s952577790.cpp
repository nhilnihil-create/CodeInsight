#include <bits/stdc++.h>
using namespace std;

long long n, x;

int main() {
  cin >> n >> x;
  if(x == 1 || x == 2 * n - 1) {
    cout << "No" << endl;
    return 0;
  }
  else
    cout << "Yes" << endl;
  if(x == n) {
    for(int i = 0; i < 2 * n - 1; ++i) {
      if(i != 0) cout << " ";
      cout << i + 1;
    }
    cout << endl;
  }
  else if(x < n) {
    for(int i = x + 1; i <= n; ++i) {
      if(i != x + 1) cout << " ";
      cout << i;
    }
    for(int i = 1; i <= n * 2 - 1; ++i)
      if(i <= x || i > n) {
        cout << " ";
        cout << i;
      }
    cout << endl;
  }
  else {
    for(int i = 1; i <= 2 * n - 1; ++i)
      if(i < n || i >= x) {
        if(i != 1) cout << " ";
        cout << i;
      }
    for(int i = n; i <= x - 1; ++i) {
      cout << " ";
      cout << i;
    }
    cout << endl;
  }
  return 0;
}