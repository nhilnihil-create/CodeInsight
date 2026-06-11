#include <bits/stdc++.h>
#define sz size
#define pb push_back
#define mper make_pair
#define PI 3.14159
#define fe first
#define se second
#define ll long long
//#define forik(i, a, b) for(ll i = a; i <= b; ++i)
#define vl vector<ll>
#define pll pair<ll, ll>
#define mal ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const ll INF = 1e15;
const ll MAXN = 2011;
ll n, x, t[MAXN * 8], a[MAXN * 2];

void build(ll v = 1, ll tl = 1, ll tr = n) {

    if(tl == tr) {t[v] = a[tl]; return;}

    ll tm = (tl + tr) >> 1;

    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);

    t[v] = min(t[v + v], t[v + v + 1]);

}

ll get(ll l, ll r, ll v = 1, ll tl = 1, ll tr = n) {

    if(r < tl || tr < l) {return INF;}
    if(l <= tl && tr <= r) {return t[v];}

    ll tm = (tl + tr) >> 1;

    return min(get(l, r, v + v, tl, tm), get(l, r, v + v + 1, tm + 1, tr));

}

int main() {

mal

cin >> n >> x;

ll ans = 0;

for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    ans += a[i];
}

n *= 2;

for(int i = (n / 2) + 1, j = 1; i <= n; ++i, ++j) {
    a[i] = a[j];
}

build();

for(int len = 1; len <= (n / 2); ++len) {

    ll sum = 0;
    ll ct = 0;

    for(int l = n - len, r = n; l >= 1; --l, --r) {
        ct++;
        if(ct == (n / 2) + 1) {break;}
        sum += get(l, r);

    }

    ans = min(ans, sum + (len * x));

}

cout << ans;

return 0;
}
