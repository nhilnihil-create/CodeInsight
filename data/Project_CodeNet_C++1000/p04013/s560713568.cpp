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
#define INF (1ll<<60)

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

int N, A;
VI V;
ll dp[51][51][2503];

ll dfs(int idx, int num, int sum) {
    if (idx == N) {
        if (num == 0 && sum == 0) return dp[idx][num][sum] = 1;
        else return dp[idx][num][sum] = 0;
    }
    if (sum < 0) return dp[idx][num][sum] = 0;
    if (dp[idx][num][sum] != -1) return dp[idx][num][sum];
    return dp[idx][num][sum] = dfs(idx+1, num-1, sum - V[idx]) + dfs(idx+1, num, sum);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> N >> A;
    V.resize(N);
    REP(i, N) cin >> V[i];
    sort(all(V));
    ll res = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        res += dfs(0, i, A * i);
    }
    cout << res << endl;

}