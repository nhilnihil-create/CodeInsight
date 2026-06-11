#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 60;

ll a[N];

int main()
{
    ll k;
    cin >> k;
    cout  << "50" << endl;

    ll x = k / 50 + 50;
    ll y = k % 50;
    ll z = x - y - 1;

    if(y == 0)
    {
        //cout << "z = " << z << endl;
        for (int i = 1; i <= 50; i ++ )
        {
            cout << z << " ";
        }
    }
    else
    {
        for (int i = 1; i <= 50 - y ; i ++ ) cout << z << " ";
        for (int i = 50 - y + 1; i <= 50; i ++ ) cout << x << " ";
    }
    cout << endl;

    return 0;
}
