#include "bits/stdc++.h"
#define ll long long
#define fr first
#define sc second
using namespace std;

const int mnx = 1e7 + 9;
const int mod = 1e9 + 7;
const double PI = acos(-1);

ll n, a, b, h[mnx];

ll f(int x){
    ll res = 0;

    for(int i = 1; i <= n; i++){
        ll hh = h[i] - x * b;
        if(hh > 0) res += (hh + (a - b) - 1) / (a - b);
    }

    return (res <= x);
}

void solve(){
    cin >> n >> a >> b;

    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }

    ll l = 0, r = mod;

    while(l + 1 < r){
        int mid = (l + r) >> 1;

        if(f(mid)) r = mid;
        else l = mid;
    }

    cout << r << '\n'
;}


int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0), cout.tie(0);
    ll tt = 1;

//    scanf("%d", &tt);

    while(tt--){
        solve();
    }

    return 0;
}
