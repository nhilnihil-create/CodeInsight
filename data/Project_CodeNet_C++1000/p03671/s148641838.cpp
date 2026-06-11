#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int ans = min(a+c,min(b+c, a+b));
    cout << ans << endl;
    return 0;
}