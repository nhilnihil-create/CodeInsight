#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b; cin >> a >> b;
    
    int ans = 0;
    ans += a + b;

    if (24 <= ans) ans -= 24;
    
    cout << ans << endl;

    return 0;
}