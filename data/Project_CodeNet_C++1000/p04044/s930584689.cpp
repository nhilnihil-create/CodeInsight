#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    sort(all(s));

    string ans = "";
    rep(i, n) ans += s[i];

    cout << ans << endl;

    return 0;
}
