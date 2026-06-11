#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;

ll mod = 1000000007;


int main() {
ll n,m; cin >> n>>m;
if (abs(n-m)>=2) {
    cout << 0 << endl;
    return 0;
}
ll ans1=1,ans2=1;
for(int i =1;i<=n;++i){
        ans1 = ans1 *i;
        ans1%=mod;
    }
    for(int i =1;i<=m;++i){
        ans2 = ans2 *i;
        ans2%=mod;
    }
if(n==m){
   cout << (ans1*ans2*2)%mod << endl;
    }
else cout << ans1*ans2%mod << endl;
}