/**
*    created: 21.06.2020 01:17:11
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    if (a <= c && c <= b) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}