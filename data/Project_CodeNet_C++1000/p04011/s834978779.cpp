#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k,x,y;
  cin >> n >> k >> x >> y;
  if (n <= k) {
    cout << x*n << endl;
  } else {
    int z = k*x;
    z += (n-k)*y;
    cout << z << endl;
  }
}