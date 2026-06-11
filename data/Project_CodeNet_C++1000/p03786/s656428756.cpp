#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<int>;

#define rep(n) for(int i = 0; i < (n); ++i)
#define Sort(a)    sort(a.begin(), a.end())
#define gSort(a)   sort(a.begin(), a.end(), greater<int>())
#define pout(n, a) cout << fixed << setprecision(n) << (a)

const int INF = 2147483647;
const ll  MOD = 1000000007;

int main() {
    int n; cin >> n;
    vector<ll> x(n);
    for(int i = 0; i < n; ++i) cin >> x[i];

    Sort(x);

    vector<ll> ssum(n+1);
    for(int i = 0; i < n; ++i) ssum[i+1] = ssum[i] + x[i];

    // 1体は生き残る
    int ans = 1;
    for(int i = n-1; i >= 0; --i) {
        int sum = 0;
        for(int j = 0; j < i; ++j) sum += x[j];

        if(2*ssum[i] >= x[i]) ans++;
        else              break;
    }

    cout << ans << endl;

    return 0;
}