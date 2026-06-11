#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;
 
int main() {
    ll n;
    cin >> n;

    vl t(n);
    rep(i, n) {
        cin >> t[i];
    }

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vl Taka(n, -1);  // Taka[i] : 高橋君の情報からわかる山iの高さ。不明なときは-1
    Taka[0] = t[0];
    ll now = t[0];  // 現在の山の高さの最大値
    exrep(i, 1, n-1) {
        if(t[i] > now) {
            Taka[i] = t[i];
            now = t[i];
        }
    }

    vl Aoki(n, -1);  // Aoki[i] : 青木君の情報からわかる山iの高さ。不明なときは-1
    Aoki[n-1] = a[n-1];
    now = a[n-1];
    for(ll i = n-2; i >= 0; i--) {
        if(a[i] > now) {
            Aoki[i] = a[i];
            now = a[i];
        }
    }

    vl v(n);  // v[i] : 二人の情報を合わせてわかる山iの高さ。不明なときは-1
    rep(i, n) {
        if(Taka[i] == Aoki[i]) {  // 二人の情報が一致している(不明なときも含めて)とき
            v[i] = Taka[i];
        }
        else {  // 二人の情報が一致していないとき
            if(Aoki[i] == -1) {
                v[i] = Taka[i];
            }
            else if(Taka[i] == -1) {
                v[i] = Aoki[i];
            }
            else {
                out(0);
                re0;
            }
        }
    }

    ll ans = 1;
    rep(i, n) {
        if(v[i] == -1) {
            ans *= min(t[i], a[i]);
            ans %= mod;
        }
        else if(min(t[i], a[i]) < v[i]) {
            out(0);
            re0;
        }
    }

    out(ans);
    re0;
}