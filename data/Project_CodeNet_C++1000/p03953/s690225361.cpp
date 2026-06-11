#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lli", &i);
    vector<ll> d(n-1);
    vector<int> x(n-1);
    for (int i = 0; i < n-1; ++i) {
        x[i] = i;
        d[i] = v[i+1]-v[i];
    }
    ll m, k;
    cin >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        swap(x[a-2], x[a-1]);
    }
    vector<int> visited(n-1);
    vector<vector<int>> cycle;
    int cnt = 0;
    for (int i = 0; i < n-1; ++i) {
        if(visited[i]) continue;
        visited[i] = 1;
        int p = x[i];
        cycle.emplace_back(0);
        cycle[cnt].emplace_back(i);
        while(p != i){
            visited[p] = 1;
            cycle[cnt].emplace_back(p);
            p = x[p];
        }
        cnt++;
    }
    vector<int> ans(n-1);
    for (auto &&c : cycle) {
        for (int i = 0; i < c.size(); ++i) {
            ans[c[i]] = c[(k+i)%((int)c.size())];
        }
    }
    ll s = v[0];
    printf("%lli\n", s);
    for (int i = 0; i < n-1; ++i) {
        s += d[ans[i]];
        printf("%lli\n", s);
    }
    return 0;
}
