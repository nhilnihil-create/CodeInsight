#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, x;
    cin >> N >> x;
    vector<ll> a(N);
    REP(i, N)
    {
        cin >> a[i];
    }

    ll ans = LONG_MAX;
    vector<ll> minA(N, LONG_MAX);
    REP(i, N)
    {
        ll magicSum = x * i;
        REP(j, N)
        {
            ll currentIndex = (j + i) % N;
            minA[j] = min(minA[j], a[currentIndex]);
            magicSum += minA[j];
        }
        ans = min(ans, magicSum);
    }

    cout << ans << endl;
}
