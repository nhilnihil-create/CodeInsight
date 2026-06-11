#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int X;
    cin >> X;
    int ans = 1;
    while ((ans * (ans + 1)) / 2 < X)
        ans++;
    cout << ans;
}