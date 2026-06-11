#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        for(int i = 1; i <= k; i++)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << 50 << endl;
        ll quo = k / 50;
        ll rem = k % 50;
        for(int i = 0; i < 50-rem; i++)
        {
            cout << quo << " ";
            quo++;
        }
        quo++;
        for(int i = 0; i < rem; i++)
        {
            cout << quo << " ";
            quo++;
        }
    }
}
