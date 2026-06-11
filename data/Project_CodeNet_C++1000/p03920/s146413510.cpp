#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0;; i++)
    {
        sum += i;
        if (sum >= n)
        {
            int d = sum - n;
            for (int j = 1; j <= i; j++)
            {
                if (j != d)
                    cout << j << endl;
            }
            return 0;
        }
    }
}