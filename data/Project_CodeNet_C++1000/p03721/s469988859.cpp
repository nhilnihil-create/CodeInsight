#include <bits/stdc++.h>

using namespace std;

#define SWAP(x,y,z) {if ( y > z ) swap(y,z); if ( x > y ) swap(x,y); if (y > z) swap(y,z);}
typedef long long ll;
typedef unsigned long long ull;

double const eps = 1e-6;
double const pi = 3.1415926535;
ll const mod = 1e9+7;

ll a[100005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    for ( int i = 1; i <= n; i++ )
    {
        int x,y;
        cin >> x >> y;
        a[x] += y;
    }

    for ( int i = 1; i <= 100000; i++ )
    {
        if ( k-a[i] <= 0 )
        {
            cout << i << '\n';
            break;
        }
         k -= a[i];
    }
 
    return 0;
}
