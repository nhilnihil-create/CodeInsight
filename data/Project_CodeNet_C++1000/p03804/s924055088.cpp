#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> N(n), M(m);
    rep(i, n) cin >> N[i];
    rep(i, m) cin >> M[i];

    //nから切り出し→比較まで
    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j <= n - m; j++)
        {
            //以降のforで比較フェイズ
            int ok = 1;
            rep(k, m)
            {
                string tmp = N[i + k].substr(j, m);
                if (tmp != M[k])
                    ok = 0;
            }
            if (ok)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}