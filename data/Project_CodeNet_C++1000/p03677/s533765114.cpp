#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
void solve(long long n, long long m, std::vector<long long> a) {
    vector<vector<int>> open_at(m + 1), close_at(m + 1);
    for(int i = 0; i < n - 1; i++) {
        open_at[a[i] % m + 1].push_back(i + 1);
    }
    vector<ll> cost(n);
    for(int i = 1; i < n; i++) {
        close_at[a[i]].push_back(i);
        cost[i] = (a[i] - a[i - 1] + m) % m;
    }
    ll running_cost = 0;
    int active = 0;
    for(int i = 1; i < n; i++) {
        running_cost += min(cost[i], a[i]);
        active += a[i] < a[i - 1];
    }
    ll ans = running_cost;
    for(int x = 2; x <= m; x++) {
        for(int i : close_at[x - 1]) {
            running_cost--;
            running_cost += cost[i];
            active--;
        }
        running_cost -= active;
        ans = min(ans, running_cost);
        active += open_at[x].size();
    }
    cout << ans << endl;
}
int main() {
    long long n;
    scanf("%lld",&n);
    long long m;
    scanf("%lld",&m);
    std::vector<long long> a(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%lld",&a[i]);
    }
    solve(n, m, std::move(a));
    return 0;
}
