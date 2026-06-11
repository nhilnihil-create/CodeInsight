#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    vector<int> v(n);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int res = 1 << 30;
    for (int i = -100; i <= 100; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            cur += (v[j] - i) * (v[j] - i);
        }

        if (res > cur) {
            res = cur;
        }
    }

    cout << res;
    return 0;
}
