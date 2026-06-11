#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll k;
ll n = 50;
ll a[55];

int main()
{
    cin>>k;
    for(ll i = 0; i < n; i++)
    {
        a[i] = n - 1 + ((k + n - 1) / n);
    }
    ll cnt = (k + n - 1) / n * n - k;
    for(ll i = 0; i < cnt; i++)
    {
        a[i] -= n + 1;
    }
    cout<<n<<endl;
    for(ll i = 0; i < n; i++)
    {
        cout<<a[i] + cnt<<' ';
    }
    return 0;
}
