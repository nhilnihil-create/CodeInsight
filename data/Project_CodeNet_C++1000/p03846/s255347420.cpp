#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    map<int, int> A;
    rep(i, n)
    {
        int a;
        cin >> a;
        A[a]++;
    }

    if (n % 2 == 0)
    {
        for (auto p : A)
        {
            if (p.first <= 0 || p.first >= n || p.second != 2)
            {
                cout << "0" << endl;
                return 0;
            }
        }
    }

    if (n % 2 == 1)
    {
        for (auto p : A)
        {
            if (p.first >= n || (p.second != 2 && p.first != 0))
            {
                cout << "0" << endl;
                return 0;
            }
        }
    }

    int ans = 1;
    rep(i, n / 2) ans = (ans * 2) % MOD;
    cout << ans << endl;
}