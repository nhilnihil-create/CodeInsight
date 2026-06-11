#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, Mi=100000, Ma=0, k1=0, kMa=0, kMi=0;
    cin >> n;
    int K[101];
    for (int i = 0; i <= 100; i++)
    {
        K[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        K[a]++;
        Ma = max(Ma, a);
        Mi = min(Mi, a);
    }
    if (Mi*2 < Ma)
    {
        cout << "Impossible";
        return 0;
    }
    else if ((Ma % 2 == 0 && K[Mi] != 1) || (Ma % 2 == 1 && K[Mi] != 2))
    {
        cout << "Impossible";
        return 0;
    }
    for (int i = Mi; i <= Ma; i++)
    {
        if (K[i] == 0)
        {
            cout << "Impossible";
            return 0;
        }
    }
    cout << "Possible";
    return 0;
}
