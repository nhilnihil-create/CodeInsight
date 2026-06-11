#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

int main(void) {
  int a, b;
  cin >> a >> b;
  if(a == b) {
    cout << "Draw" << endl;
  } else if(a == 1 || a > b && b != 1) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
  }
}