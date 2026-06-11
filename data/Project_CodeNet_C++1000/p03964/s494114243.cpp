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
    int N;
    cin >> N;
    ull T = 1, A = 1;
    while (N--) {
        ull a, b;
        cin >> a >> b;
        if (a < b) {
            ull k = T / a + ((T % a) > 0);
            ull T1 = k * a;
            ull A1 = k * b;
            if (T1 >= T && A1 >= A) {
                T = T1;
                A = A1;
            } else {
                k = A / b + ((A % b) > 0);
                A = k * b;
                T = k * a; 
            }
        } else if (a > b) {
            ull k = A / b + ((A % b) > 0);
            ull A1 = k * b;
            ull T1 = k * a;
            if (T1 >= T && A1 >= A) {
                T = T1;
                A = A1;
            } else {
                k = T / a + ((T % a) > 0);
                A = k * b;
                T = k * a; 
            }
        } else {
            T = max(T, A);
            A = T;
        }
    }
    cout << A + T << endl;
}