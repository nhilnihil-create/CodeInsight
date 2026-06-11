#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int A,B;
  cin >> A >> B;

  if (A%3==0 || B%3==0 || (A+B)%3==0) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}
