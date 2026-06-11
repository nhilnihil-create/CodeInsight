#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = unsigned long long;
using p = pair<int, int>;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> l(N);
    rep(i, 0, N)
    {
        cin >> l[i];
    }

    sort(l.begin(), l.end(), greater<int>());

    int ans = 0;
    rep(i, 0, K)
    {
        ans += l[i];
    }

    cout << ans << endl;
    return 0;
}
