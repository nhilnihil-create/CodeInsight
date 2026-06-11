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
    map<int, int> diff;
    bool solve = 1;
    int parity;
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        if(i == 0)
        {
            parity = d%2;
        }
        else
        {
            if(d%2 != parity)
            {
                solve = 0;
            }
        }

        diff[d]++;
    }

    if(!solve)
    {
        cout << 0 << endl;
        return 0;
    }

    if(n%2 == 0)
    {
        for(auto x: diff)
        {
            if(x.second != 2)
            {
                solve = 0;
                break;
            }
        }
        if(!solve)
        {
            cout << 0 << endl;
            return 0;
        }
        else
        {
            ll ans = 1;
            ll co = n/2;
            while(co--)
            {
                ans *= 2;
                if(ans > 1000000007)
                {
                    ans %= 1000000007;
                }
            }

            cout << ans << endl;
        }
    }
    else if(n%2 == 1)
    {
        for(auto x: diff)
        {
            if((x.first != 0 && x.second != 2) || (x.first == 0 && x.second != 1))
            {
                solve = 0;
                break;
            }
        }
        if(!solve)
        {
            cout << 0 << endl;
            return 0;
        }
        else
        {
            ll ans = 1;
            ll co = n/2;
            while(co--)
            {
                ans *= 2;
                if(ans > 1000000007)
                {
                    ans %= 1000000007;
                }
            }

            cout << ans << endl;
        }

    }


}
