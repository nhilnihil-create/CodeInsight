#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  vector<ll> v = {A, B, C};
  sort(v.begin(), v.end());
  if((A % 2 == 0 || B % 2 == 0) || C % 2 == 0) {
    cout << 0 << endl;
  }
  else {
    cout << v.at(0) * v.at(1) << endl;
  }
}
