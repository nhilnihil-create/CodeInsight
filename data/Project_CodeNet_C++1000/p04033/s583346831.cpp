#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int a, b;

int main() {
  cin >> a >> b;
  if (a > 0) {
    cout << "Positive" << endl;
  }else if (b < 0) {
    if ((a - b)% 2 == 0) {
      cout << "Negative" << endl;
    }else{
      cout << "Positive" << endl;
    }
  }else{
    cout << "Zero" << endl;
  }
  return 0;
}
