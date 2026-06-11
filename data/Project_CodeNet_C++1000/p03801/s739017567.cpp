#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vint = vector<int>;
using vll = vector<ll>;
template<typename T> using uset = unordered_set<T>;
template<typename T1, typename T2> using umap = unordered_map<T1, T2>;

constexpr int INF = (1 << 30) - 1;
constexpr ll LLINF = 1LL << 60;
constexpr int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr char el = '\n';
constexpr int mod = 1000000007;

template<typename T> T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }
template<typename T> T lcm(T a, T b) { return (a / gcd(a, b) * b); }
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

int main() {
        ll N;
        ll ans[100005] = {};
        map<ll,Pl> mp;

        cin >> N;
        for (ll i = 1; i <= N; i++) {
                ll a;
                cin >> a;
                if (mp.find(a) == mp.end()) mp[a].first = i;
                mp[a].second++;
        }

        ll total = 0;
        ll minv = N;
        for (auto itr = mp.rbegin(); itr != mp.rend(); itr++) {
                auto v = *itr;
                auto it2 = itr;
                it2++;

                ll prev;
                if (it2 == mp.rend()) prev = 0;
                else prev = it2->first;

                total += v.second.second; 
                minv = min(minv, v.second.first);
                ans[minv] += total * (v.first - prev);
        }

        for (ll i = 1; i <= N; i++) {
                cout << ans[i] << el;
        }

        return (0);
}
