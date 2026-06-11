#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
#define FOR(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define eFOR(i,a,n) for(int (i)=(a);(i)<=(n);(i)++)
#define SORT(i) sort((i).begin(),(i).end())
#define rSORT(i,a) sort((i).begin(),(i).end(),(a))
constexpr auto INF = 1000000000;
constexpr auto LLINF = 1LL << 60;
constexpr auto mod = 1000000007;
constexpr auto MOD = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; }return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; }return 0; }

ll c[51][51] = {};

int main() {

    int n, a, b;
    ll v;
    cin >> n >> a >> b;
    map<ll, int> m;
    FOR(i, 0, n) {
        cin >> v;
        m[v]++;
    }

    vector<ll> d;
    for (auto i : m)d.push_back(i.first);
    rSORT(d, [](ll a, ll b) {return a > b; });
    double ave = 0;

    int cnt = a, itr = 0;
    if (m[d[0]] > a)ave = d[0];
    else {
        while (1) {
            if (cnt <= m[d[itr]]) {
                ave += d[itr] * cnt;
                break;
            }
            else {
                ave += d[itr] * m[d[itr]];
                cnt -= m[d[itr++]];
            }
        }
        ave /= a;
    }
    printf("%.11lf\n", ave);

    eFOR(i, 0, n)eFOR(j, 0, i) {
        if (j == 0 || j == i)c[i][j] = 1LL;
        else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]);
    }

    ll ans = 0;
    if (d[0] != d[itr]) {
        ans = c[m[d[itr]]][cnt];
    }
    else eFOR(i, a, min(m[d[0]], b))ans += c[m[d[0]]][i];
    cout << ans << endl;
}