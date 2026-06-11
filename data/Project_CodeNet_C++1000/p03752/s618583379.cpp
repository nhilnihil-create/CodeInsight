#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// マクロ
// forループ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(ll)(b);i--)
// xにはvectorなどのコンテナ
#define ALL(x) (x)begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
// 出力
#define PRINT(x) cout<<(x)<<endl
#define PRINTA(x,n) REP(i,n)PRINT(x[i])
// 定数
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
// 略記
#define PB push_back
#define MP make_pair

const int MAX_N = 15;

int N, K, a[MAX_N];

int b[MAX_N];

int main() {
    cin >> N >> K;
    REP(i, N) cin >> a[i];

    ll min_cost = INF;
    REP(bit, 1<<N) {
        REP(i, N) {
            b[i] = a[i];
        }

        ll cur_cost = 0;
        int colors = 1;
        int max_h = b[0];

        FOR(i, 1, N-1) {
            if (b[i] > max_h) {
                colors++;
                max_h = b[i];
            }
            else if (bit & 1<<i) {
                cur_cost += max_h + 1 - b[i];
                b[i] = max_h + 1;
                colors++;
                max_h = b[i];
            }
        }
        if (colors >= K) min_cost = min(min_cost, cur_cost);
    }
    PRINT(min_cost);
    return 0;
}