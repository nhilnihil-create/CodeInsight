#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<string, int>;
int main()
{
    ll k;
    cin >> k;
    if(k == 0)
    {
        cout << 2 << endl;
        cout << "1 1" << endl;
    }
    else if(k == 1)
    {
      cout << 2 << endl;
      cout << "2 0" << endl;
    }
    else if(k <= 50)
    {
        cout << k << endl;
        for(int i = k; i > 0; i--)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << 50 << endl;
        ll x = k / 50;
        ll y = k % 50;
        x--;
        vector<ll> ans(50);
        for(int i = 0; i < 50; i++)
        {
            ans[i] = 50 + x - i;
        }
        for(int i = 0; i < y; i++)
        {
            ans[i]++;
        }
        for(int i = 0; i < 50; i++)
        {
            cout << ans[i] << " ";
        }
    }
}

