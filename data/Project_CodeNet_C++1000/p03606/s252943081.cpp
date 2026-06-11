#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  int a, b, x = 0;
  
  rep (cnt, N) {
    cin >> a >> b;
    x += (b - a + 1);
  }
  
  cout << x << endl;  
}