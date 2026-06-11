#include <bits/stdc++.h>

using namespace std;

long long ans,a,b,n,i;

int main()
{
    cin >> n;
    for(i = 0; i < n; i ++)
    {
        cin >> a;
        ans += (a + b) / 2;
        if((a + b) % 2 == 1 && a != 0) b = 1;
        else b = 0;
    }
    cout << ans << endl;
    return 0;
}
