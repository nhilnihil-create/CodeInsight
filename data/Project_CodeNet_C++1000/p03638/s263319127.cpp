#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int H, W, N;
    cin >> H >> W;
    cin >> N;
    vector<int> a(N, 0);
    rep(i, N) cin >> a[i];
    vector<vector<int>> res;
    bool odd = true;
    int num = 1;
    int cnt = 1;
    rep(i, H)
    {
        vector<int> row;
        rep(j, W)
        {
            row.push_back(num);
            cnt++;
            if (a[num - 1] < cnt)
            {
                num++;
                cnt = 1;
            }
        }
        if (i % 2 == 1)
        {
            reverse(row.begin(), row.end());
        }
        res.push_back(row);
    }
    rep(i, H)
    {
        rep(j, W)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}