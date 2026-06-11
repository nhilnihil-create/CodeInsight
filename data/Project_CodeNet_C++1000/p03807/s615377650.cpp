#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int N;

int main()
{

    cin >> N;
    vector<ll> a(N);
    int o = 0,
        e = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            e++;
        }
        else
        {
            o++;
        }
    }
    while (o > 1)
    {
        o -= 2;
        e++;
    }
    if (e > 0 && o > 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}
