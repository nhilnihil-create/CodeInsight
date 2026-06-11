#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  int ans =0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a , b;
    cin >> a >> b;
    ans += (b - a + 1);
  }
cout << ans << endl;
}
