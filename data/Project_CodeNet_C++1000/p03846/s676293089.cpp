#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  bool check = true;

  if (n%2 == 0) {//n:even
    for (int i = 0; i < n; i = i + 2) {
      if (!(i + 1 == a.at(i) && i + 1 == a.at(i+1))) {
        check = false;
        break;
      }
    }
  } else {//n:odd
    for (int i = 1; i < n; i = i + 2) {
      if (a.at(1) == 0 || a.at(0) != 0) {//0は1こまでou最初は0
        check = false;
        break;
      }

      if ((i + 1 == a.at(i) && i == a.at(i+1))) {
        check = false;
        break;
      }
    }
  }

  if (check) {
    ll cnt = 1;
  	for (int i = 1; i <= n / 2; i++) {
      cnt = (cnt << 1) % 1000000007;
  	}
  	cout << cnt << endl;
     } else {
    cout << "0" << endl;
  }
}
