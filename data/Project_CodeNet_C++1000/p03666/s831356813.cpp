#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    ll x = abs(a-b);
    ll y = abs(c-d);
    if((n-1)*c <= x && x <= (n-1)*d)
    {
        cout << "YES" << endl;
        return 0;
    }
    for(int i = 1; i <= (n-1)/2; i++)
    {
        if((n-1-i)*c - i*d <= x && (n-1-i)*d - i*c >= x)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    if(n % 2 == 1)
    {
        if(x <= y * (n-1) / 2)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
