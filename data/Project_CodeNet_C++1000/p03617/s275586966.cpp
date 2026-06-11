#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll Q, H, S, D, N;
    cin >> Q >> H >> S >> D;
    cin >> N;

    ll minPriceS, minPriceD;
    minPriceS = min(4 * Q, min(2 * H, S));
    minPriceD = min(2 * minPriceS, D);
    ll ans = (N / 2) * minPriceD + (N % 2) * minPriceS;

    cout << ans << endl;
}
