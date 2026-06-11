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
ll a[N];
int32_t main(){
    ll n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    ll ans=0;
    for (int i=0;i<n;i++){
        if (a[i]==i+1){
            swap(a[i],a[i+1]);
            ans++;
        }
    }
    cout << ans;
}
