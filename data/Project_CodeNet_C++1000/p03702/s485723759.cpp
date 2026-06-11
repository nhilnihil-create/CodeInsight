#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<typename U, typename V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}
 
int main() {
    FAST_IO();
    ll N, A, B; cin >> N >> A >> B;
    vector<int> H(N);
    rep(i, N) cin >> H[i];
    ll S = 0, lo = 0, hi = 1e9;
    while(lo <= hi) {
        ll mid = (lo + hi) >> 1;
        ll sum = 0;
        rep(i, N) {
            sum += max(0LL, (H[i] - B * mid + A - B - 1) / (A - B));
        }
        if(sum <= mid) {
            S = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }
    cout << S << "\n";
}