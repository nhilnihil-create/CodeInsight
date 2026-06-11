#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N,A,B;
  cin >> N >> A >> B;
  cout << max(0LL,(B * (N - 1) + A) - (A * (N - 1) + B) + 1) << endl;
  return 0;
}
