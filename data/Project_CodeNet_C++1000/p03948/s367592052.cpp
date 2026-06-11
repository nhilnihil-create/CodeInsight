#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll n,t;
    cin >> n >> t;

    ll a[n];
    for(int i = 0; i < n; i++)
        scanf("%lld",&a[i]);

    ll mn = a[0];
    ll p = 0, mp = 0;
    ll c = 0;

    for(int i = 1; i < n; i++)
    {
        if(a[i] <  mn)   mn = a[i];
        if(a[i] >= mn)   p = a[i] - mn;

        if(p > mp)         mp = p,c = 1;
        else if(p == mp)   c++;
    }

    cout << c << endl;

    return 0;
}
