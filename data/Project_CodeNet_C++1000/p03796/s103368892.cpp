#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;

int main() {
  ll n;
  cin >> n;
  ll sum = 1;
  for (ll i = 1; i <= n; i++) {
    sum *= i;
    sum %= mod;
  }
  cout << sum << endl;
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/