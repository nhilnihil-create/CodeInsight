#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 50;

ll C[N + 1][N + 1];

void ncp(int n = N) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == i || j == 0) {
        C[i][j] = 1;
      } else {
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      }
    }
  }
}

int main() {
  ncp();
  int n, a, b;
  cin >> n >> a >> b;
  vector<ll> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x.begin(), x.end(), greater<ll>());
  double sum = 0;
  
  for (int i = 0; i < a; i++) {
    sum += x[i];
  }
    
  double avg = sum / a;
  
  cout << fixed << std::setprecision(6) << avg << '\n';
  
  ll ans = 0;
  int used = 0, tot = 0;
  for (int i = 0; i < n; i++) {
    if (x[a - 1] == x[i]) {
      if (i < a)
        used += 1;
      tot += 1;
    }
  }
  
  if (x[0] == x[a - 1]) {
    for (ll i = a; i <= min(tot, b); i++) {
      ans += C[tot][i];
    }
  } else {
    ans = C[tot][tot - used];
  }

  
  cout << ans << endl;
  
  return 0;
}
