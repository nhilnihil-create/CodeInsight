#include <iostream>
#include <vector>

using namespace std;

#define int long long

signed main()
{
    int n, t;
    vector<int> ts;

    cin >> n >> t;

    ts.resize(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> ts[i];
    }

    ts.push_back(1e9 * 2 + 10);

    int ans = 0;
    int prev = 0;
    int now = 0;

    for(int i = 0; i < ts.size(); ++i)
    {
        if(now < ts[i])
        {
            //cout << now << " " << prev << endl;
            ans += now - prev;
            prev = ts[i];
        }
        now = ts[i] + t;
    }

    cout << ans << endl;

    return 0;
}