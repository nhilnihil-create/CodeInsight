#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();

signed main() {
    vector<ll> a(7);
    cin >> a;
    ll ans = 0;
    vector<int> explore = {0, 3, 4};
    int oddCount = 0;
    bool check = true;
    for (auto idx : explore) {
        if (a[idx] < 1) check = false;
        if (a[idx] % 2 == 1) oddCount++;
    }
    if (oddCount >= 2 && check) {
        ans += 3;
        for (auto idx : explore) a[idx]--;
    }
    for (auto idx : explore) ans += (a[idx] / 2) * 2;
    ans += a[1];
    cout << ans << endl;
}
