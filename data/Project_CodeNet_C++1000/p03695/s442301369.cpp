#include <iostream>
#include <vector>
#include <string>

#define rep(i, cc, n) for (int i = cc; i < n; ++i)
using namespace std;

int main()
{
    int N;
    cin >> N;

    bool rank[8];
    rep(i, 0, 8)
    {
        rank[i] = false;
    }

    int over3200 = 0;
    rep(i, 0, N)
    {
        int a;
        cin >> a;

        if (a >= 3200)
        {
            over3200++;
        }
        else
        {
            rank[a / 400] = true;
        }
    }

    int ans = 0;
    rep(i, 0, 8)
    {
        if (rank[i])
        {
            ans++;
        }
    }

    if (ans >= 1)
    {
        cout << ans << " " << (ans + over3200) << endl;
    }
    else
    {
        cout << 1 << " " << over3200 << endl;
    }
}
