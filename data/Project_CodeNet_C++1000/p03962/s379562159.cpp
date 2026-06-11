#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)

signed main()
{
    int a,b,c; cin >> a >> b >> c;

    int ans;
    if ((a == b) && (b == c)) ans = 1;
    else if ((a != b) && (b != c) && (c != a)) ans = 3;
    else ans = 2;

    cout << ans << endl;

    return 0;
}
