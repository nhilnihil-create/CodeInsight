#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  long long N, t;
  cin >> N >> t;
  for(int i = 0; i < N-1; i++){  
    long long k;
    cin >> k;
    t = t / __gcd(t, k) * k;
  }
  cout << t <<endl;
}
