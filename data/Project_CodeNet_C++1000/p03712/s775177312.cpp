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

    vector<string> a(h);
    rep(i, h) cin >> a[i];
    rep(i, w + 2) cout << '#';
    cout << '\n';
    rep(i, h)
    {
        cout << '#';
        cout << a[i];
        cout << '#' << '\n';
    }
    rep(i, w + 2) cout << '#';
    cout << '\n';
    return 0;
}
