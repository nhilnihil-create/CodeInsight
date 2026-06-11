#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int N; cin >> N;
  int ev = 0, od = 0;
  for(int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    x % 2 == 0 ? ev++ : od++;
  }
  if(od % 2 == 1) cout << "NO" << endl;
  else cout << "YES" << endl;
}