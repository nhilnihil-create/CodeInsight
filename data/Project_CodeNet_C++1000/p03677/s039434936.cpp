#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = numeric_limits<int>::max() - 1e8;
const ll INFLL = numeric_limits<ll>::max() - 1e17;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    cin >> a;
    auto calcDist = [&](ll now, ll next) {
        if (now <= next) return next - now;
        else return (m - now) + next;
    };
    auto moveIdx = [&](ll now, ll add) {
        ll temp = now + add;
        if (temp > m) temp = (temp % m);
        return temp;
    };
    ll base = 0;
    for (int i = 0; i + 1 < n; i++) base += calcDist(a[i], a[i + 1]);
    ll count = 0, sumMinus = 0;
    vector<ll> plus(m + 1), minus(m + 1), resetPlus(m + 1);
    for (int i = 0; i + 1 < n; i++) {
        if (calcDist(a[i], a[i + 1]) == 1) continue;
        if (a[i] > a[i + 1] && a[i] + 2 <= m) {
            sumMinus += calcDist(a[i], m) - 1;
            count++;
        } else if (a[i + 1] == m) {
            sumMinus += calcDist(a[i], a[i + 1]) - 1;
            count++;
        }
        plus[moveIdx(a[i], 2)]++;
        minus[moveIdx(a[i + 1], 1)]++;
        resetPlus[moveIdx(a[i + 1], 1)] += calcDist(a[i], a[i + 1]) - 1;
    }
    ll ans = INFLL;
    for (int i = 1; i <= m; i++) {
        count -= minus[i];
        sumMinus -= resetPlus[i];
        count += plus[i];
        sumMinus += count;
        ans = min(ans, base - sumMinus);
    }
    cout << ans << endl;
}
