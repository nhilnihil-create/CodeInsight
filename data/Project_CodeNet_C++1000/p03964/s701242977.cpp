#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main()
{
    ll n,a,b,x=1,y=1;
    cin >> n;

    while(n--)
    {
        cin >> a >> b;
        ll y2 = (((x-1) / a) + 1) * b;
        if(y2 >= y)
        {
            y = y2;
            x = (((x-1) / a) + 1) * a;
            continue;
        }

        x = (((y-1) / b) + 1) * a;
        y = (((y-1) / b) + 1) * b;
    }

    cout << x+y << endl;
}
