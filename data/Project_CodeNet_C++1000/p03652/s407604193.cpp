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
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
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
    ll n, m;
    cin >> n >> m;

    vvl a(n, vl(m));  // a[i][j] : 人iがj番目に好きなスポーツ
    rep(i, n) {
        rep(j, m) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    vl used(m);  // used[i] : 0のときスポーツiを実施する。1のとき実施しない
    vl v(n);  // v[i] : 人iが参加するスポーツの番号
    ll ans = n;
    rep(loop, m) {
        vl cnt(m);  // cnt[i] : スポーツiに参加する人数
        rep(i, n) {
            // 実施されているスポーツの中で人iの最も好きなスポーツを探す
            while(used[ a[i][v[i]] ]) {
                v[i]++;
            }
            cnt[ a[i][v[i]] ]++;  // 人iはスポーツa[i][v[i]]に参加
        }
        pair<ll, ll> p = make_pair(-1, -1);  // p = (参加人数の最大値, 参加人数最大のスポーツの番号)
        rep(i, m) {
            chmax(p, make_pair(cnt[i], i));
        }
        chmin(ans, p.first);  //「参加人数の最大値」の最小値を更新
        used[p.second] = 1;  // 以降p.second番目のスポーツは実施しない
    }
    
    out(ans);
    re0;
}