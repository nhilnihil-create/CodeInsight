#include <bits/stdc++.h>

using namespace std;

#define SWAP(x,y,z) {if ( y > z ) swap(y,z); if ( x > y ) swap(x,y); if (y > z) swap(y,z);}
typedef long long ll;
typedef unsigned long long ull;

double const eps = 1e-6;
double const pi = 3.1415926535;
ll const mod = 1e9+7;

int a[10000];

void solve()
{

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a,b,c;
    cin >> a >> b >> c;
    if ( c >= a && c <= b ) cout << "Yes" << '\n';
    else cout << "No" << '\n';

    return 0;
}
