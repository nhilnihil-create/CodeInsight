#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define trav(a, x) for (auto& a : x)
using ull = uint64_t;
using ll = int64_t;
using PII = pair<int, int>;
using VI = vector<int>;

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(A v) {
bool first = true; string res = "{";
for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); }
res += "}"; return res; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H); debug_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int MAX_N = 205;

int N, M, R;
ll d[MAX_N][MAX_N];
int RR[10];
const ll INF = 1000000000000;

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> N >> M >> R;
    REP(i, R) cin >> RR[i];
    REP(i, N + 2) REP(j, N + 2) {
        if (i == j) d[i][j] = 0;
        else d[i][j] = INF;
    }
    int x, y, w;
    REP(i, M) {
        cin >> x >> y >> w;
        d[x][y] = w;
        d[y][x] = w;
    }
    for (int k = 1; k < N + 1; k++) {
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    sort(RR, RR + R);
    ll ans = LLONG_MAX;
    do {
        ll dist = 0;
        FOR(i, 1, R - 1) {
            dist += d[RR[i - 1]][RR[i]];
        }
        ans = min(ans, dist);
    } while(next_permutation(RR, RR + R));
    cout << ans << endl;

}