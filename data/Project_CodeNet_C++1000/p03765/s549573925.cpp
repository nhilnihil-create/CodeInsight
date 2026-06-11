#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair <int, int> ii;

string s, t;
int psums[100001], psumt[100001], q;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("INP.INP", "r", stdin);
//    freopen("OUT.OUT", "w", stdout);
    cin >> s >> t >> q;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == 'A') psums[i + 1] = 1;
        else psums[i + 1] = -1;
        psums[i + 1] += psums[i];
    }
    for (int i = 0; i < (int) t.size(); i++) {
        if (t[i] == 'A') psumt[i + 1] = 1;
        else psumt[i + 1] = -1;
        if (i == 0) continue;
        psumt[i + 1] += psumt[i];
    }
    while (q--) {
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        int S, T;
        S = psums[y] - psums[x - 1];
        T = psumt[t] - psumt[z - 1];
        S %= 3;
        T %= 3;
        if (S < 0) S+=3;
        if (T < 0) T+=3;
//        cerr << "S, T: " << S << " " << T << '\n';
        if (S == T) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
