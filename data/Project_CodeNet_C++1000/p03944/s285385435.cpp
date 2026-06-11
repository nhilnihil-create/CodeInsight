#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int w, h, n;
    cin >> w >> h >> n;
    vector<pair<int, int>> xy(n);
    for (int i = 0; i < n; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if (t3 > 2)
            xy[i] = make_pair(t2, t3);
        else
            xy[i] = make_pair(t1, t3);
    }
    int lw = 0, uw = w, lh = 0, uh = h;
    for (auto x : xy)
    {
        if (x.second > 2)
        {
            if (x.second % 2 == 1)
                lh = max(x.first, lh);
            else
                uh = min(x.first, uh);
        }
        else if (x.second % 2 == 1)
            lw = max(x.first, lw);
        else
            uw = min(x.first, uw);
    }
    if ((uw - lw) < 0 || (uh - lh) < 0)
        cout << 0 << endl;
    else
        cout << (uw - lw) * (uh - lh) << endl;
}
