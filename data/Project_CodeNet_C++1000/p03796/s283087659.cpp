#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll M = 0,ans = 1;
  cin >> M;
  rep(i,M){
    ans *= i + 1;
    ans %= 1000000007;
  }
  cout << ans;
}