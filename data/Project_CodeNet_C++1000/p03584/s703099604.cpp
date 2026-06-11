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

ll N, K;
map<ll, ll> Pattern;    // key: 探索パターン, val: その時の最大値

int main()
{
    cin >> N >> K;

    // K から見るべきパターンを列挙
    Pattern[K] = 0;     // K 自身
    for(int i = 31; i >= 0; --i) {
        if(((K >> i) & 1) == 1) {
            ll key = K & (~(1 << i));
            key |= ((1 << i) - 1);
            Pattern[key] = 0;
        }
    }

    ll ans = 0;
    REP(i, N) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        for(auto pat : Pattern) {
            if((pat.first | a) == pat.first) {
                pat.second += b;
                Pattern[pat.first] = pat.second;
                ans = max(ans, pat.second);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
