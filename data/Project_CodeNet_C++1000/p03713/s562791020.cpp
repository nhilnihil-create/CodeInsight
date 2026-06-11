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

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    ull H, W;
    cin >> H >> W;
    ull ans = INT_MAX;
    for (int i = 1; i < H; i++) {
        ull b1 = i * W;
        if (H - i == 1) {
            ull a = W / 2;
            ull b = W - a;
            ull b2 = a;
            ull b3 = b;
            ull areaD = max(b1, max(b2, b3)) - min(b1, min(b2, b3));
            ans = min(ans, areaD);
        } else {
            ull h = H - i;
            ull a = h / 2;
            ull b = h - a;
            ull b2 = a * W;
            ull b3 = b * W;
            ull areaD = max(b1, max(b2, b3)) - min(b1, min(b2, b3));
            ans = min(ans, areaD);
            a = W / 2;
            b = W - a;
            b2 = a * h;
            b3 = b * h;
            areaD = max(b1, max(b2, b3)) - min(b1, min(b2, b3));
            ans = min(ans, areaD);
        }
    }
    swap(H, W);
    for (int i = 1; i < H; i++) {
        ull b1 = i * W;
        if (H - i == 1) {
            ull a = W / 2;
            ull b = W - a;
            ull b2 = a;
            ull b3 = b;
            ull areaD = max(b1, max(b2, b3)) - min(b1, min(b2, b3));
            ans = min(ans, areaD);
        } else {
            ull h = H - i;
            ull a = h / 2;
            ull b = h - a;
            ull b2 = a * W;
            ull b3 = b * W;
            ull areaD = max(b1, max(b2, b3)) - min(b1, min(b2, b3));
            ans = min(ans, areaD);
            a = W / 2;
            b = W - a;
            b2 = a * h;
            b3 = b * h;
            areaD = max(b1, max(b2, b3)) - min(b1, min(b2, b3));
            ans = min(ans, areaD);
        }
    }
    cout << ans << endl;
}