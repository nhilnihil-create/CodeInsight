#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a,b,c;
  cin >> a >> b >> c;

  if (b-a==c-b) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
