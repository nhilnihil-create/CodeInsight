#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define inf 1000000100

int main()
{
    int n;
    cin >> n;
    ll ans = 1;
    for(int i = 2; i <= n; i++)
    {
        if(ans >= 1000000007/i)
        {
            ans %= 1000000007;
        }
        ans *= i;
    }

    ans %= 1000000007;

    cout << ans << endl;
}