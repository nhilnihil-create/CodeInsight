#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz size
#define se second
#define fe first
#define mper make_pair
#define all(x) x.begin(), x.end()
#define mal ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define vl vector<ll>
#define vi vector<int>
#define vli vector <pair <ll, int> >
#define vll vector <pair <ll, ll> >
#define vii vector <pair <int, int> >
using namespace std;

const ll MAXN = 1e5 + 100;
const ll inf = 1e-16;
ll n, k, a[MAXN], pref[MAXN], ans = inf, b[MAXN];


int main(){

//freopen("ladder.in", "r", stdin);
//freopen("ladder.out", "w", stdout);

cin >> n >> k;

for(int i = 1; i <= n; ++i) {

    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];

    b[i] = b[i - 1] + max(0ll, a[i]);

}

for(int l = 1, r = l + k - 1; r <= n; ++l, ++r) {

    if(r <= n) {

        ll sum = max(pref[r] - pref[l - 1], 0ll) + max(b[l - 1] + b[n] - b[r], 0ll);

        ans = max(ans, sum);

    }

}



cout << ans;

return 0;
}
