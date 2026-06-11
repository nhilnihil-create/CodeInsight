#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    int h, w, base = 65;
    cin >> h >> w;
    rep(i, h)
    {
        rep(j, w)
        {
            string s;
            cin >> s;
            if (s == "snuke")
            {
                cout << (char)(base + j) << (i + 1) << endl;
                return 0;
            }
        }
    }
    // end

    return 0;
}
