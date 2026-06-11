#include "bits/stdc++.h"
#define ll long long
#define fr first
#define sc second
using namespace std;

const int mnx = 1e6 + 9;
const int mod = 1e9 + 7;

ll n, k, a[mnx], t[mnx], h;
pair <ll, ll> z[mnx];

ll get(int x){
    ll res = 0;
    for(; x > 0; x -= (x & -x)){
        res += t[x];
    }
    return res;
}

void upd(int x){
    for(; x <= n; x += (x & -x)){
        t[x]++;
    }
}

void solve(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] -= k;
    }

    ll sum = 0;

    for(int i = 1; i <= n; i++){
        sum += a[i];
        z[i] = {sum, i};
    }

    sort (z + 1, z + n + 1);

    ll ans = 0;

    for(int i = 1; i <= n; i++){
        upd(z[i].sc);
        ans += get(z[i].sc);
        if(z[i].fr < 0) ans--;
    }

    cout << ans << '\n';
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tt = 1;

//    scanf("%d", &tt);

    while(tt--){
        solve();
    }

    return 0;
}
