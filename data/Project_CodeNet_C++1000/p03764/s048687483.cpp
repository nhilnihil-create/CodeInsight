#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
const i64 MOD = 1e9 + 7;

struct int_m {
    static int64_t mod;
    int64_t v;
    int_m() {}
    int_m(int64_t x) : v(x) {}
    int_m operator+(const int_m &y) { return (v + y.v) % mod; }
    int_m operator-(const int_m &y) { return (v - y.v + mod) % mod; }
    int_m operator*(const int_m &y) { return (v * y.v) % mod; }
    void operator+=(const int_m &y) { *this = *this + y; }
    void operator-=(const int_m &y) { *this = *this - y; }
    void operator*=(const int_m &y) { *this = *this * y; }
    friend istream &operator>>(istream &ist, int_m &m) { return ist >> m.v; }
    friend ostream &operator<<(ostream &ost, int_m &m) { return ost << m.v; }
};

int64_t int_m::mod = MOD;

int main() {
    int n, m;
    cin >> n >> m;
    vector<i64> x(n), y(m);
    for(auto &a : x) cin >> a;
    for(auto &a : y) cin >> a;
    sort(WHOLE(x)), sort(WHOLE(y));
    int_m ans = 1;
    for(int b = 0; b < 2; b++) {
        int_m S = 0;
        int_m acc = 0;
        for(int i = n - 1; i > 0; i--) {
            acc += x[i];
            S += acc - int_m((n - i) * x[i - 1]);
        }
        ans *= S;
        swap(x, y);
        swap(n, m);
    }
    cout << ans << endl;
    return 0;
}