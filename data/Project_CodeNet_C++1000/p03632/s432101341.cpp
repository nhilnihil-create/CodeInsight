#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a <= d && b >= c) cout << min(b,d) - max(a,c) << endl;
    else cout << 0 << endl;

    return 0;
}