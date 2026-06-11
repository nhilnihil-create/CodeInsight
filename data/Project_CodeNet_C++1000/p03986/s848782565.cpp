#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    string X;
    cin >> X;

    ll n = X.size();
    bool flagS = false, flagT = false;
    ll countS = 0, countT = 0;
    ll sumDelete = 0;
    REP(i, n)
    {
        if (X[i] == 'S')
        {
            if (flagS)
            {
                countS++;
            }
            else
            {
                flagS = true;
                if (flagT)
                {
                    flagT = false;
                    sumDelete += 2 * min(countS, countT);
                }
                countS = max(1ll, countS - countT + 1);
                countT = 0;
            }
        }
        else if (X[i] == 'T')
        {
            if (flagT)
            {
                countT++;
            }
            else
            {
                flagT = true;
                flagS = false;
                countT = 1;
            }
        }
    }
    sumDelete += 2 * min(countS, countT);

    ll ans = n - sumDelete;
    cout << ans << endl;
}
