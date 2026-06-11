#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
ll pow(int n, int e)
{
    ll ans = 1;
    for (int i = 0; i < e; i++)
    {
        ans *= n;
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << k * pow(k - 1, n - 1) << endl;

    return 0;
}
