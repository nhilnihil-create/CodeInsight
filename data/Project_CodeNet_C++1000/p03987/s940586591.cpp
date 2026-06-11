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
    int N;
    cin >> N;
    vector<ll> a(N + 1), idx(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    auto calc = [&](ll left, ll now, ll right) {
        ll dif = right - left - 1, temp = 0;
        // if (dif == 1) return 1LL;
        ll maxValue = (dif + 1) / 2;
        ll minValue = min(now - left, right - now);
        if (minValue == maxValue) {
            temp += maxValue * (maxValue + 1) - (maxValue * (dif % 2 == 1));
        } else {
            temp += minValue * (minValue + 1);
            temp += (maxValue - minValue) * 2 * minValue -(minValue * (dif % 2 == 1));
        }
        return temp;
    };
    ll ans = 0;
    set<ll> explore;
    explore.insert(0);
    explore.insert(N + 1);
    for (int i = 1; i <= N; i++) {
        auto itr = explore.upper_bound(idx[i]);
        ll left = *next(itr, -1);
        ll right = *itr;
        ans += calc(left, idx[i], right) * i;
        explore.insert(idx[i]);
    }
    cout << ans << endl;
}