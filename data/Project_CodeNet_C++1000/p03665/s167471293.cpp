#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  int odd=0;
  rep(i,n) {
    int a;
    cin >> a;
    if(a%2!=0) odd++; 
  }
  ll ans = 1;
  rep(i,n-1) ans *= 2;
  if(odd==0&&m==1) ans = 0;
  else if(odd==0&&m==0) ans *= 2;
  cout << ans << endl;
  return 0;
}