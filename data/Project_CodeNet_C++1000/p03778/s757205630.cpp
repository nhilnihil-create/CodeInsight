#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int w,a,b; cin >> w >> a >> b; 
   cout << (abs(a-b)-w<0 ? 0 : abs(a-b)-w) << endl;
}