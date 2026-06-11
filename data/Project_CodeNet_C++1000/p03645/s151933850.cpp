#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "O3"
#define rep(i,a,n) for(long long i=a; i<n; i++)
typedef long long ll;
typedef pair<int,int> P;
const ll MOD = (int)1e9+7;
const ll INF = MOD*MOD;
const double EPS = 1e-9;
const ll powll = 1LL<<1;

/*
while(!frag && cin >> a >>b, a|b)
*/

int main(void){
   int n,m; cin >> n >> m;
   int a[n] = {},b[n] = {};
   rep(i,0,m){
      int c,d; cin >> c >> d;
      c--; d--;
      if(c==0) a[d]=1;
      if(d==n-1) b[c]=1;
   }

   string ans = "IMPOSSIBLE\n";
   rep(i,0,n){
      if(a[i] == 1 && b[i] == 1) ans = "POSSIBLE\n";
   }
   cout << ans;
}