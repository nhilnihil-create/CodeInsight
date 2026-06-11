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

    ll ans = 1;
    bool isInc = false, isDec = false;
    REP(i, N - 1)
    {
        if (A[i + 1] > A[i])
        {
            if (isDec)
            {
                ans++;
                isDec = false;
            }
            else if (!isInc && !isDec)
            {
                isInc = true;
            }
        }
        else if (A[i + 1] < A[i])
        {
            if (isInc)
            {
                ans++;
                isInc = false;
            }
            else if (!isInc && !isDec)
            {
                isDec = true;
            }
        }
    }

    cout << ans << endl;
}
