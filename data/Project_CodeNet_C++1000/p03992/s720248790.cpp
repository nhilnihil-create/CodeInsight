#include <bits/stdc++.h>
using namespace std;
#define _overload3(_1,_2,_3,_4,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n,s) for (int i=a;s>0?i<n:i>n;i+=s)
#define rep(...) _overload3(__VA_ARGS__,per,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
const int inf = 1e9+10, mod = 1e9+7; const long long llinf = 1e18;
// head

int main(){
  string s;
  cin >> s;
  string ans;
  rep(i,4) ans += s[i];
  ans += " ";
  rep(i,4,12) ans += s[i];
  cout << ans << endl;
}