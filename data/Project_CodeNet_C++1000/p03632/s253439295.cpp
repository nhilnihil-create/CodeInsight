#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int ans = min(b,d) - max(a,c);
    if(ans < 0) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}