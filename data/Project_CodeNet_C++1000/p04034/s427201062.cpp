#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> x(M), y(M);
    REP(i, M)
    {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    vector<ll> countBall(N, 1);
    vector<bool> isRed(N, false);
    isRed[0] = true;

    REP(i, M)
    {
        if (isRed[x[i]])
        {
            isRed[y[i]] = true;
            if (countBall[x[i]] == 1)
            {
                isRed[x[i]] = false;
            }
        }
        countBall[x[i]]--;
        countBall[y[i]]++;
    }
    ll ans = 0;
    REP(i, N)
    {
        if (isRed[i])
        {
            ans++;
        }
    }

    cout << ans << endl;
}
