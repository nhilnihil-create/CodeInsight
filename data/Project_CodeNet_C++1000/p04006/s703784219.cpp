#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define endl '\n'
using namespace std;
const int N=3000;
ll a[N];
ll b[N];
int32_t main(){
    ll n,x;
    cin >> n >> x;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        b[i]=a[i];
    }
    ll ans=(ll)1e18+100;
    for (int i=0;i<=n;i++){
        ll cnt=i*x;
        for (int j=1;j<=n;j++){
            cnt+=b[j];
        }
        ans=min(ans,cnt);
        for (int j=1;j<=n;j++){
            ll z=j-i-1;
            z+=n;
            z%=n;
            if (z==0) z=n;
            b[j]=min(b[j],a[z]);
        }
    }
    cout << ans << endl;
}
