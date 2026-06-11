#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, x;

int main()
{
    cin>>n>>x;
    ll y = x - n;
    if(x == 1 || x == 2 * n - 1)
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    for(ll i = 0; i < 2 * n - 1; i++)
    {
        printf("%lld\n", (i + y + 2 * n - 1) % (2 * n - 1) + 1);
    }
    return 0;
}
