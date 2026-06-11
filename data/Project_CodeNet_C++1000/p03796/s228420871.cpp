#include <bits/stdc++.h>
using namespace std;
#define X 1000000007LL

int main()
{
    int n;
    long long ans = 1;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        ans *= i;
        ans %= X;
    }
    cout << ans << endl;
}