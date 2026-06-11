#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n, k, x;
  cin >> n >> k;
  int a = 0;
  rep(i, n) {
    cin >> x;
    if (x < k - x) {
      a += x * 2;
    } else {
      a += (k - x) * 2;
    }
  }
  cout << a << endl;
}
