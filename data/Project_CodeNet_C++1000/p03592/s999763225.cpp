#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n, m,k;
  cin >>n>>m>>k;
  bool can = false;
  if (k%n==0 || k%m==0) can = true;
  rep(a,n+1) rep(b,m+1) {
    int num = a*m+b*n-2*a*b;
    if (num == k) can = true;
  }
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}