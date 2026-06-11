#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    //一次元の配列F1に格納
    vector<int> F1;
    rep(i, n)
    {
        int a;
        cin >> a;
        rep(j, a) F1.push_back(i + 1);
    }

    //２次元配列F2に格納
    vector<vector<int>> F2;
    rep(i, h)
    {
        vector<int> f;
        for (int j = i * w; j < (i + 1) * w; j++)
            f.push_back(F1[j]);
        F2.push_back(f);
    }

    rep(i, h)
    {
        if (i % 2 == 1)
        {
            reverse(F2[i].begin(), F2[i].end());
            rep(j, w) cout << F2[i][j] << " ";
        }
        else
        {
            rep(j, w) cout << F2[i][j] << " ";
        }
        cout << endl;
    }
}