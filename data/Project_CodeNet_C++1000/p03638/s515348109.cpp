#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll
#define all(v) v.begin(), v.end()
#define reps(__i, a, b) for (int __i = a; i < b; i++)
#define rep(__i, n) reps(__i, 0, n)

const ll INF = (1ll << 60);
const ll MOD = (ll)1e9 + 7;

signed main()
{
    int h, w, n;
    cin >> h >> w >> n;
    int arr[100100];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ret[110][110];
    int color = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i % 2)
                ret[i][j] = color + 1;
            else
                ret[i][w - j - 1] = color + 1;
            arr[color]--;
            if (arr[color] == 0)
                color++;
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
}