#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define chmax(a, b) a = (a >= b ? a : b)
#define chmin(a, b) a = (a <= b ? a : b)
#define out(a) cout << a << endl
#define outa(a, n) { rep(_, n) cout << a[_] << " "; cout << endl; }
#define outp(a, n) { cout << endl; rep(_, n) cout << a[_].F << " " << a[_].S << endl; }
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
#define FIX(a) fixed << setprecision(a)
#define LB(v, n) (int)(lower_bound(all(v), n) - v.begin())
#define UB(v, n) (int)(upper_bound(all(v), n) - v.begin())
ll pow(ll a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }


ll nck(int n, int k) { ll ret = 1; rep(i, k) {ret *= n - i; ret /= i + 1; } return ret; } // n <= 60


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
   
    
    

    int N, A, B;
    cin >> N >> A >> B;
    
    
    vector<ll> v(N);
    rep(i, N) cin >> v[i];
    sort(all(v), greater<ll>());
    
    double ave = 0;
    rep(i, A) ave += v[i];
    out(FIX(7) << ave / A);
    
    int sum_a = 0, sum_n = 0;
    rep(i, A) if (v[i] == v[A - 1]) { sum_a++; sum_n++; }
    rep3(i, A, N) if (v[i] == v[A - 1]) sum_n++;
    
    
    
    if (sum_a == A) {
        // out(sum_n << " " << sum_a);
        ll cnt = 0;
        for (sum_a = A; sum_a <= B; ++sum_a) cnt += nck(sum_n, sum_a);
        // rep3(i, A, sum_n + 1) cnt += nck(sum_n, i);
        out(cnt);
    } else {
        // out(sum_n << " " << sum_a);
        ll cnt = 0;
        cnt = nck(sum_n, sum_a);
        out(cnt);
    }
}


