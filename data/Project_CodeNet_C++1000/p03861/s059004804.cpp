#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define _START_ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define _END_ return 0;

using namespace std;

int main()
{   
    _START_
    
    ll int a, b, x, c = 0;
    cin >> a >> b >> x;
    if (a % x)
    {
        if (a + (x - (a % x)) <= b)
        {
            a += (x - (a % x));
            c++;
        }
    }
    else
        c++;
    c += ((b - a) / x);
    cout << c;
    
    _END_
}