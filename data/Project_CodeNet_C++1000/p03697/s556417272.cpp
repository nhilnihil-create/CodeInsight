#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a,b;
  cin >> a >> b;

  if (a+b<10) {
    cout << a+b << endl;
  }

  else if (a+b>=10) {
    cout << "error" << endl;
  }
  return 0;
}
