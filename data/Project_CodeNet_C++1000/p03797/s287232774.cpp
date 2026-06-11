#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll N,M; cin >> N >> M;
  if (M <= 2 * N) cout << M/2 << endl;
  else cout << (M+2*N)/4 << endl;
}