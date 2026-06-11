#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll x)
{
    char ans;
    cout << "? " << x << endl;
    cout.flush();
    cin >> ans;
    return (ans == 'Y');
}

int main()
{
    ll n = 1;
    while(1)
    {
        if (!check(n)) break;
        n *= 10;
        if(n > (ll)1e10)
        {
            ll z = 1;
            while(n)
            {
                if(!check(n+1))
                {
                    z = n*10;
                    break;
                }
                else n/= 10;
            }
            cout << "! " << z << "\n";
            return 0;
        }
    }
    ll r = n*10 - 1, l = n-1;
    while(l < r)
    {
        ll mid = (l+r) >> 1;
        if(check(mid))
        {
            n = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << "! " << n/10 << "\n";
    cout.flush();
    return 0;
}
