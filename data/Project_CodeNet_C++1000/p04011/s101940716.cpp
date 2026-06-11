#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;
 

int main() {
  int n,k,x,y;
  cin >> n >> k >> x >> y;

  if(n<=k) cout << n*x << endl;
  else cout << k*x + (n-k)*y << endl;
}