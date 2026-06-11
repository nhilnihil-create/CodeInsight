#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = (b-a)*(n-2)+1; //(b*(n-1)+a)-(a*(n-1)+b)+1
  if(a>b||ans<0) ans = 0;
  cout << ans << endl;
}
