#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    vector<ll> sumA(n, 0);
    // -, +, -, +, ...の順番
    ll countFirst = 0;
    sumA[0] = a[0];
    if (sumA[0] >= 0) 
    {
        countFirst += sumA[0] + 1;
        sumA[0] = -1;
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        sumA[i] = sumA[i - 1] + a[i];
        if (i % 2 == 1)
        {
            if (sumA[i] <= 0)
            {
                countFirst += -sumA[i] + 1;
                sumA[i] = 1;
            }
        }
        else
        {
            if (sumA[i] >= 0)
            {
                countFirst += sumA[i] + 1;
                sumA[i] = -1;
            }
        }
    }

    // +, -, +, -, ...の順番
    ll countSecond = 0;
    sumA[0] = a[0];
    if (sumA[0] <= 0)
    {
        countSecond += -sumA[0] + 1;
        sumA[0] = 1;
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        sumA[i] = sumA[i - 1] + a[i];
        if (i % 2 == 1)
        {
            if (sumA[i] >= 0)
            {
                countSecond += sumA[i] + 1;
                sumA[i] = -1;
            }
        }
        else
        {
            if (sumA[i] <= 0)
            {
                countSecond += -sumA[i] + 1;
                sumA[i] = 1;
            }
        }
    }
    ll ans = min(countFirst, countSecond);

    cout << ans << endl;
}
