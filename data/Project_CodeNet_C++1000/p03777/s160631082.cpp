#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  char A,B;
  cin >> A >> B;

  if (A==B) {
    cout << "H" << endl;
  } else if (A!=B) {
    cout << "D" << endl;
  }
  return 0;
}
