#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n;
    ll ans=0;
    cin>>n;
    vector<ll> a(3*n);
    rep(i,3*n) cin>>a[i];
    sort(a.begin(),a.end());
    for (int i=n; i<3*n; i++) {
        if ((i-n)%2==0) ans+=a[i];
    }
    cout<<ans<<endl;
}
