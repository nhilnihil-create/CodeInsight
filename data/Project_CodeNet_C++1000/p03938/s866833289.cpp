#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; cin >> N;
  int p[N]; rep(i,N) { int tmp; cin >> tmp; tmp--; p[tmp]=i; }
  rep(i,N) cout << (i+1)*N << " "; cout << endl;
  rep(i,N) cout << (N-i)*N + p[i] << " "; cout << endl;
  return 0;
}