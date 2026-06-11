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

    if (x == 1 || x == 2 * N - 1)
    {
        cout << "No" << endl;
        return 0;
    } 

    if (N == 2)
    {
        cout << "Yes" << endl;
        REP(i, 2 * N - 1)
        {
            cout << i + 1 << endl;
        }
        return 0;
    }

    vector<ll> p(2 * N - 1, -1);
    vector<bool> isUsed(2 * N, false);
    if (x != 2)
    {
        p[N - 2] = x - 1;
        p[N - 1] = x;
        p[N] = x + 1;
        p[N + 1] = x - 2;
        isUsed[x - 1] = true;
        isUsed[x] = true;
        isUsed[x + 1] = true;
        isUsed[x - 2] = true;

    }
    else
    {
        p[N - 2] = x + 1;
        p[N - 1] = x;
        p[N] = x - 1;
        p[N + 1] = x + 2;
        isUsed[x + 1] = true;
        isUsed[x] = true;
        isUsed[x - 1] = true;
        isUsed[x + 2] = true;
    }
    REP(i, 2 * N - 1)
    {
        if (p[i] == -1)
        {
            ll value = i + 1;
            while(isUsed[value])
            {
                value++;
                value = value > 2 * N - 1 ? 1 : value;
            }
            isUsed[value] = true;
            p[i] = value;
        }
    }

    cout << "Yes" << endl;
    REP(i, 2 * N - 1)
    {
        cout << p[i] << endl;
    }
}
