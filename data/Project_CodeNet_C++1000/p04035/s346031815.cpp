#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {

    ios::sync_with_stdio(false); cin.tie(0);

    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    rep (i, n) cin >> a[i];

    int hozon = -1;
    rep (i, n - 1) {
        if (a[i] + a[i + 1] >= l) {
            hozon = i + 1;
            break;
        }
    }

    if (hozon == -1) cout << "Impossible" << '\n';
    else {
        cout << "Possible" << endl;
        for (int i = 1; i < hozon; i++) cout << i << '\n';
        for (int i = n - 1; i > hozon; i--) cout << i << '\n';
        cout << hozon << '\n';
    }
    
    return 0;
}