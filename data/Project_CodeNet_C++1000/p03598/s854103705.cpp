#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n,k,ans;
  cin >> n >> k;
  ans = 0;
  rep(i,n){
    int x,l;
    cin >> x;
    l = min(x, k-x);
    ans += l*2;
  }
  cout << ans << endl;
}