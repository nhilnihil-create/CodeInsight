
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e15;
static const ll mod = 1e9+7;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

int main() {
    int n;
    cin >> n;
    vector<P> ps(n);
    rep(i, n) {
        cin >> ps[i].first >> ps[i].second;
    }
    sort(ps.begin(), ps.end());
    auto score = ps.back();
    cout << score.first + score.second << endl;
    return 0;
}
