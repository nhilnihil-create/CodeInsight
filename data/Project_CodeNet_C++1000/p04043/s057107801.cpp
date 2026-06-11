#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    vector<int> n(3);
    rep(i, 3) cin >> n[i];

    sort(all(n));

    cout << (n[0] == 5 && n[0] == n[1] && n[2] == 7 ? "YES" : "NO") << '\n';
    return 0;
}
