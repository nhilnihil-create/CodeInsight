#include <bits/stdc++.h>
using namespace std;

void solve(){
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  int sum = 0;
  sum = a[0] + a[1] + a[2];
  if(sum == 17 && (a[0] == 5 || a[0] == 7) && (a[0] + a[1] == 10 || a[0] + a[1] == 12))
  {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(){
  solve();
  return 0;
}
