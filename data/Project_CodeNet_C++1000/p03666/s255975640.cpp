#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

ll N, A, B, C, D;

bool check(ll m)
{
    return (C * (N - m - 1) - D * m <= B - A) && (B - A <= (N - m - 1) * D - C * m);
}

int main()
{
    cin >> N >> A >> B >> C >> D;
    for (ll i = 1; i < N; i++)
    {
        if (check(i) == true)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}