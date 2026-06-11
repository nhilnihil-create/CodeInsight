#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

//constexpr long long MOD = 1000000007;
constexpr long long MOD = 998244353;
//constexpr int INF = 1001001001;
constexpr ll INF = 1001001001001001001ll;
constexpr double EPS = 1e-10;
using number = long long;


number GCD(number a, number b) {
    return b != 0 ? GCD(b, a % b) : a;
}
number LCM(number a, number b) {
    return a * (b / GCD(a, b));
}

int main() {
    ll n, x; cin >> n >> x;
    ll a = x, b = n - x;
    if (a > b) swap(a, b);
    ll ans = n;
    while (1) {
        if (b % a == 0) {
            ans += (2 * (b / a) - 1) * a;
            break;
        }
        else {
            ans += 2 * (b / a) * a;
            ll tmp = a;
            a = b % a;
            b = tmp;
        }
    }
    cout << ans << endl;
}