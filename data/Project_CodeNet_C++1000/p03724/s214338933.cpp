#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vvl = vector<vl>;
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

void print(const std::vector<ll> &v) {
    std::for_each(v.begin(), v.end(), [](ll x) { std::cout << x << " "; });
    std::cout << std::endl;
}
// xとyに足すのは
// xからroot yからrootという操作と同じ
//それぞれのnodeの登場回数が偶数ならよい
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    map<int, int> cnt;
    REP(i, M) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    for(auto tmp : cnt) {
        if(tmp.second % 2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}