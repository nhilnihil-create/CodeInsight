#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int  long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
using namespace std;
/// age ye mosh dp ro baze dashti dp tedad baz shodeye baste nashode yadet nare !!
/// joooob zadam
const int N=2e5+100;
ll h[N];
int32_t main(){
    ll n,a,b;
    cin >> n >> a >> b;
    for (int i=1;i<=n;i++){
        cin >> h[i];
    }
    ll l=-1,r=1e9+100;
    while(r-l>1){
        ll mid=(r+l)/2;
        ll ans=0;
        for (int i=1;i<=n;i++){
            ll z=h[i]-mid*b;
            if (z>0){
                ans+=(z+a-b-1)/(a-b);
            }
        }
        if (ans<=mid){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    cout << r;
}
