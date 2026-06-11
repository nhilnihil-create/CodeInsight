#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll inf2 = 1000000000000000000;
const ll mod = 1000000007;


int main() {
   int n;
   cin >> n;
   vector<ll>a(n);
   vector<ll>b(n);
   rep(i, 0, n){
       cin >> a[n-1-i] >> b[n-1-i];
   }
   ll ans = 0;
   rep(i, 0, n){
       if((a[i]+ans)%b[i]==0)continue;
       ans += (b[i]-(a[i]+ans)%b[i]);
       //cout << ans << endl;
   }
   cout << ans << endl;
}