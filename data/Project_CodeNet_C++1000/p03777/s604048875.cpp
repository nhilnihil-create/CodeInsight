#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   char a,b; cin >> a >> b;
   bool c,d;
   c = (a=='H' ? true : false);
   d = (b=='H' ? true : false);
   cout <<  (((c&&d)||((!c)&&(!d))) ? "H" : "D") << endl;
}