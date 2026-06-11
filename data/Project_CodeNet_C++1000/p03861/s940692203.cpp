#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    //freopen("input.txt", "r", stdin);

    ll a, b, x;
    cin >> a >> b >> x;

    ll cnt = 0;

    cnt = cnt + (b/x) - (a/x);
    if(a % x == 0)
        cnt++;

    cout << cnt << "\n";

    return 0;
}
