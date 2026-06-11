#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N, x; cin >> N >> x;
  if (x==1||x==2*N-1) { cout << "No" << endl; return 0; }
  int diff = x-N;
  cout << "Yes" << endl;
  rep(i,2*N-1) cout << (i+diff+(2*N-1))%(2*N-1)+1 << " ";
  cout << endl;
  return 0;
}