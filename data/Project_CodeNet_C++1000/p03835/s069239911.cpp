#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int k, s;
    cin >> k >> s;

    ll count = 0;
    for (int x = 0; x <= k; ++x)
    {
        for (int y = 0; y <= k; ++y)
        {
            int z = s - y - x;
            if (z >= 0 && z <= k)
                ++count;
        }
    }
    cout << count << endl;
}