#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
   
typedef long long ll;
const int N = 200010;
const ll mod = 1e9 + 7;
 
int main()
{
    int a, b;
    cin >> a >> b;
    int p, ans = (int)2e9;
    p = b - a;
    if (p >= 0) ans = min(ans, p);
    p = b + a + 1;
    if (p >= 0) ans = min(ans, p);
    p = -b - a + 1;
    if (p >= 0) ans = min(ans, p);
    p = -b + a + 2;
    if (p >= 0) ans = min(ans, p);
    printf("%d\n", ans);
    return 0;
}