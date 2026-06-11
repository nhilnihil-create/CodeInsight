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
/// khodaya komak kon

/// ba z_func hatman dafe baad bezan

int32_t main(){
    ll ans=0;
    ll t=0;
    ll n;
    cin >> n;
    for (int i=1;i<1e6;i++){
        t+=i;
        ans++;
        if (t>=n){
            cout << ans << endl;
            return 0;
        }

    }
}
