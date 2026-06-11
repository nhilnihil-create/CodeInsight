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

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    cin >> a;
    sort(a.begin(), a.end());
    auto judge = [&](int idx) {
        bitset<5001> base = 1;
        for (int i = 0; i < N; i++) {
            if (i == idx || a[i] > 5000) continue;
            base |= (base<<a[i]);
        }
        bool ok = true;
        for (int i = max(0, K - a[idx]); i < K; i++) {
            if (base[i] == 1) ok = false;
        }
        return ok;
    };
    int left = 0, right = N - 1;
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (judge(mid)) left = mid;
        else right = mid;
    }
    if (right == 1) {
        cout << judge(0) << endl;
    } else if (right == N - 1) {
        cout << right + judge(right) << endl;
    } else {
        cout << right << endl;
    }
}
