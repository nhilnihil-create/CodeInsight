
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ll s,k;
    cin >> k >> s;
    ll cnt = 0;
    ll r;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (s - i - j >= 0 && s - i - j <= k)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;




}
