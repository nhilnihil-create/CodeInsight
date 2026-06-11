#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);

    int X; cin >> X;
    int ans = 0;
    while ((ans * (ans + 1)) / 2 < X)
        ans++;
    cout << ans << "\n";
}