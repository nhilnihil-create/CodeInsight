#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
using ll = long long;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}
// https://misteer.hatenablog.com/entry/AGC005-Bs
int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    REP(i, N) {
        cin >> a[i];
        a[i]--;
    }
    //ある値×その区間長さ
    vector<int> idx(N);
    REP(i, N) { idx[a[i]] = i; }
    set<int> s;
    ll ans = 0;
    REP(x, N) {
        int l, r;
        //小さいものから始める
        int i = idx[x];
        s.insert(i);
        auto iterator = s.find(i);
        if(iterator == s.begin()) {
            //自分より小さいものが存在しない
            l = -1;
        } else {
            iterator--;
            l = *iterator;
        }
        iterator = s.find(i);
        iterator++;
        if(iterator == s.end()) {
            //自分より小さいものが存在しない
            r = N;
        } else {
            r = *iterator;
        }
        // cout << (x + 1) * (i - l) * (r - i) << endl;
        // cout << i - l << " ::::" << r - i << endl;
        ans += (x + 1) * (i - l) * (r - i);
    }
    cout << ans << endl;
    return 0;
}