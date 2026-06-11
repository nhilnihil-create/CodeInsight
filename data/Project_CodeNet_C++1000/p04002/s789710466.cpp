#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))

#define MOD 1000000007
#define INF 1000000000
#define MAX_N 100010

ll H, W, N;
ll ans[10];
vector< pair<ll, ll> > black;   // 黒く塗られたところ
map< pair<ll, ll>, ll > sq;         // black に影響を受ける左上 (i, j) の 3 * 3 領域

int main()
{
    cin >> H >> W >> N;
    ZERO(ans);
    REP(i, N) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        a--; b--;
        black.push_back( make_pair(a, b) );
        for(ll i = -2; i < 1; ++i) {
            for(ll j = -2; j < 1; ++j) {
                if(a + i >= 0 && b + j >= 0 &&
                   a + i < H - 2 && b + j < W - 2) {
                    sq[ make_pair(a + i, b + j) ]++;
                    //printf("a: %lld b: %lld  sq[%lld, %lld]: %lld -> %lld\n",
                    //        a, b, a+i, b+j, sq[ make_pair(a + i, b + j) ]-1,
                    //        sq[ make_pair(a + i, b + j) ]);
                }
            }
        }
    }
    for(auto tmp : sq) {
        ans[tmp.second]++;
    }
    ans[0] = (W - 2) * (H - 2);
    for(int i = 1; i < 10; ++i) {
        ans[0] -= ans[i];
    }
    REP(i, 10) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
