#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    vector < int > a;
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < (int)a.size(); i += 2) ans += a[i];
    cout << ans << '\n';
    return 0;
}
