#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int n, m, xi, yi;
    vi  red, cnt;
    cin >> n >> m;

    cnt.resize(n, 1), red.resize(n, false);
    red[0] = true;

    for (int i = 0; i < m; ++i)
    {
        cin >> xi >> yi, xi--, yi--;

        red[yi] |= red[xi];

        if (cnt[xi] == 1)
            red[xi] = false;
        cnt[xi] -= 1;
        cnt[yi] += 1;
    }

    cout << accumulate(red.begin(), red.end(), 0) << endl;
    return 0;
}
