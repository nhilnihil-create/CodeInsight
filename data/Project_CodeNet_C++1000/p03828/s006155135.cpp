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
    vi sieve(n+1, 1);
    ll ans = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!sieve[i])
        {
            continue;
        }
        for(int j = i; j <= n; j *= i)
        {
            for(int k = j; k <= n; k += j)
            {
                sieve[k] = 0;
                sieve[i]++;
            }
        }

    }

    for(int i = 2; i <= n; i++)
    {
        if(sieve[i])
        {
            ans *= (sieve[i]+1);
            if(ans >= 1000000007)
            {
                ans %= 1000000007;
            }
        }
    }

    cout << ans << endl;

}