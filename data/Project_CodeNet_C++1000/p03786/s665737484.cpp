#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(ALL(A));

    vector<ll> sumA(N);
    sumA[0] = A[0];
    REP(i, N - 1)
    {
        sumA[i + 1] = sumA[i] + A[i + 1];
    }
    ll ans = 1;
    REP(i, N - 1)
    {
        if (A[N - 1 - i] <= 2 * sumA[N - 2 - i])
        {
            ans++;
        }
        else
        {
            break;
        }
    }

    cout << ans << endl;
}
