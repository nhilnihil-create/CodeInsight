#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007で割った余り
const long long mod = 1e9 + 7;

using ll = long long;
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpll vector<pll>
#define vpii vector<pii>

using pint  = pair<int, int>;
using plint = pair<ll, ll>;

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rrep1(i, n) for (int i = ((int)(n)); i > 0; --i)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back

// template<class T>bool maxc(T &a, const T &b) { if (a<b) { a=b; return 1; } }
// template<class T>bool minc(T &a, const T &b) { if (b<a) { a=b; return 1; } }

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(5);

    // 入力
    string s;
    cin >> s;

    // 処理
    int    cnt = 0;
    string s0  = "CODEFESTIVAL2016";
    rep(i, sz(s)) {
        if (s0[i] != s[i]) {
            cnt++;
        }
    }

    // 出力
    cout << cnt << endl;

    return 0;
}
