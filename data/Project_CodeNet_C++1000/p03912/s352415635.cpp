#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int x[100010], zero = 0, half = 0;
map<int,int> mp, tmp, same;
int c[100010]; // 各k (mod m) に対して、同じ数のペアがいくつあるかをカウント

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, n) cin >> x[i];

    rep(i, n){
        mp[x[i]%m]++;
        tmp[x[i]]++;
    }
    for(auto e : tmp){
        same[e.first%m] += e.second / 2;
        if (e.first%m == 0) zero += e.second;
        if (m%2 == 0 && e.first%m == m/2) half += e.second;
    }

    int ans = 0;
    ans += zero / 2;

    for(int k = 1; k <= m/2;  k++){
        if (m%2 == 0 && k == m/2) {
            ans += half / 2;
            continue;
        }
        int p, q;
        if (mp[k] <= mp[m-k]) p = k, q = m-k;
        else p = m-k, q = k;
        ans += mp[p];
        ans += min((mp[q] - mp[p]) / 2, same[q]);
    }

    cout << ans << endl;

    return 0;
}
