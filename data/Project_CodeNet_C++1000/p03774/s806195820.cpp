#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,m;
    cin>>n>>m;
    vector<ll> a(n),b(n),c(m),d(m);
    rep(i,n) cin>>a[i]>>b[i];
    rep(i,m) cin>>c[i]>>d[i];
    rep(i,n) {
        ll dis=abs(a[i]-c[0])+abs(b[i]-d[0]);
        int index=1;
        for (int j=1; j<m; j++) {
           ll res=abs(a[i]-c[j])+abs(b[i]-d[j]);
           if (res<dis) {
               index=j+1;
               dis=res;
           }
        }
        cout<<index<<endl;
    }
}
