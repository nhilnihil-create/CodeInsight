#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N; cin >> N;
  ll p[N]; ll ab[N];
  for (ll i = 0; i < N; i++) {
    cin >> p[i];
  }
  for (ll i = 0; i < N; i++) {
    ab[p[i]-1] = 1e9-N+i+1;
  }
  for (ll i = 0; i < N; i++) {
    cout << 30000*(i+1) << " ";
  }
  cout << endl;
  for (ll i = 0; i < N; i++) {
    cout << ab[i]-30000*(i+1) << " ";
  }
  cout << endl;
}