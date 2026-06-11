#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> P3;
typedef pair<P ,P> PP;
constexpr ll MOD = ll(1e9) + 7;
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
constexpr int MAX_N = int(1e5) + 5;
constexpr double EPS = 1e-8;
constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i > 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

int main() {
    ll n, m, a[MAX_N], imos[MAX_N*2]{}, sum[MAX_N]{};
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        ll dif = (a[i+1]-a[i]+m) % m;
        // xにしたとき回数が減るような区間の個数をimosで数える
        if(dif > 1){
            imos[a[i]+2]++;
            imos[a[i]+dif+1]--;
        }
        sum[a[i+1]+1] += dif-1;  // a[i+1]+1にしたときの増加分
        sum[1] += min(dif, a[i+1]);  // 1のとき
    }
    for(int i=0;i<m*2;i++){
        imos[i+1] += imos[i];
    }
    for(int i=2;i<=m;i++){
        sum[i] += sum[i-1] - (imos[i]+imos[i+m]);
    }

    ll ans = LLINF;
    for(int i=1;i<=m;i++){
        ans = min(ans, sum[i]);
    }
    cout << ans << endl;
    return 0;
}
