#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7;
const double PI = acos(-1);
ll c[55][55] = {};

ll comb (ll a, ll b){
    if (b > a) return 0;
    if (c[a][b] != 0) return c[a][b];
    if (a == 0 || b == a || b == 0) return c[a][b] = 1;
    return c[a][b] = comb(a-1, b) + comb(a-1, b-1);
}


int main (){
    cout << fixed << setprecision(20);
    ll a, b, n, rep_a=0, rep_total = 0;
    long double media = 0;
    cin >> n >> a >> b;

    vector<ll> v(n);

    for (auto& x: v) cin >> x;

    sort(all(v));
    reverse(all(v));

    for (int i=0; i<a; i++){
        media+=v[i];
    }
    media/=a;
    cout << media << endl; 

    for (int i=0; i<n; i++){
        if (v[i] == v[a-1]){
            rep_total++;
            if (i < a) rep_a++;
        }
    }
    ll ans = 0;
    // cout << rep_a << " " << rep_total << endl;
    if (rep_a == a){
        for (int i=a; i<=b; i++){
            ans += comb(rep_total, i);
        }
    }
    else {
        ans = comb(rep_total, rep_a);
    }

    cout << ans << endl;
    return 0;
}