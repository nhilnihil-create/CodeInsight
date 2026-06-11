#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        ans += i;
    }
    cout << ans << endl;
    return 0;
}