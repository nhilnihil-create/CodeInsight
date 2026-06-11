#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c[i];

    rep(i, h)
    {
        rep(j, 2)
        {
            cout << c[i] << '\n';
        }
    }
    return 0;
}
