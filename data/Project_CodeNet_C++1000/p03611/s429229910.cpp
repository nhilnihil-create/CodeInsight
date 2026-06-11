#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main()
{

    int N;
    cin >> N;

    int t;
    int m = 0;

    int a[100100] = {0};
    rep(i, N) cin >> t, a[t]++;

    for (int i = 1; i < 100001; ++i)
    {
        m = max(m, a[i - 1] + a[i] + a[i + 1]);
    }

    cout << m << endl;

    return 0;
}
