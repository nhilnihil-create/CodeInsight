#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    REP(i, N)
    {
        cin >> a[i];
    }

    vector<ll> sumA(N + 1), sumMaxA(N + 1);
    sumA[0] = 0;
    sumMaxA[0] = 0;
    REP(i, N)
    {
        sumA[i + 1] = sumA[i] + a[i];
        sumMaxA[i + 1] = sumMaxA[i] + max(0ll, a[i]);
    }

    ll ans = 0;
    REP(i, N - K + 1)
    {
        ll sumNowWhite = 0;
        ll sumNowBlack = 0;
        sumNowWhite += sumMaxA[i];
        sumNowBlack += sumMaxA[i];
        sumNowBlack += sumA[i + K] - sumA[i];
        sumNowWhite += sumMaxA[N] - sumMaxA[i + K];
        sumNowBlack += sumMaxA[N] - sumMaxA[i + K];
        ans = max(ans, sumNowWhite);
        ans = max(ans, sumNowBlack);
    }

    cout << ans << endl;
}
