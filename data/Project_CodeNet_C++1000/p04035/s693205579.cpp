#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, L;
ll a[100005];
ll x;

int main()
{
    scanf("%lld%lld", &n, &L);
    for(ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        if(i > 1 && a[i] + a[i - 1] >= L) x = i - 1;
    }
    if(x == 0)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    cout<<"Possible"<<endl;
    for(ll i = 1; i < x; i++) cout<<i<<endl;
    for(ll i = n - 1; i >= x; i--) cout<<i<<endl;
    return 0;
}
