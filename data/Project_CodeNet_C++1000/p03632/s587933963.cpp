#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> t(101);
    for (int i = a; i <= b; i++)
        t[i]++;
    for (int i = c; i <= d; i++)
        t[i]++;

    int cnt = 0;
    rep(i, 101)
    {
        if (t[i] == 2)
            cnt++;
    }
    if (cnt > 0)
        cnt--;
    cout << cnt << endl;
    return 0;
}