#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int a[100100];

int main()
{
    int N;
    cin >> N;
    rep(i, N)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    int res = 0;
    for (int i = 1; i < 100100; i++)
    {
        res = max(res, a[i - 1] + a[i] + a[i + 1]);
    }
    cout << res << endl;
    return 0;
}