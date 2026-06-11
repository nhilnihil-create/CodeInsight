#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

ll ab(ll x){
    return max(x,-x);
}

int main(){
    fastIO;
    int n;
    cin >> n;
    ll sum = 0;
    ll a[n];
    for(int i = 0 ; i < n ; i ++ ){
        cin >> a[i];
        sum += a[i];
    }
    ll v1 = 0, v2 = 0;
    ll mn = (ll)1e18;
    for(int i = 0 ; i < n-1 ; i ++ ){
        v1 += a[i];
        v2 = sum - v1;
        mn = min(mn, ab(v1-v2));
    }
    cout << mn;
    return 0;
}
