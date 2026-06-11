#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main()
{
    ll n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    ll ans = 0, i = 0;
    if(s1[0] == s2[0])
    {
        ans += 3;
        i++;
    }
    else
    {
        ans += 6;
        i+=2;
    }
    while(i<n)
    {
        if(s1[i] == s2[i])
        {
            if(s1[i-1] == s2[i-1])
            {
                ans *= 2;
                ans %= MOD;
            }
        }
        else
        {
            if(s1[i-1] == s2[i-1])
            {
                ans *= 2;
                ans %= MOD;
            }
            else
            {
                ans *= 3;
                ans %= MOD;
            }
            i++;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}
