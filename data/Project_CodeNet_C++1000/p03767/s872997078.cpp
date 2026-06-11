#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int N;
    cin >> N;
    vector<ll> a(3 * N);
    rep(i, 3 * N) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    ll sum = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        if (i % 2 == 1)
            sum += a[i];
    }
    cout << sum << endl;
    return 0;
}