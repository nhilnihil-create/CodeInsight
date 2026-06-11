#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

string s;

ll a[128];
ll ans;

int main()
{
    cin>>s;
    ll n = s.size();
    for(ll i = 0; i < n; i++)
    {
        a[s[i]]++;
    }
    for(ll i = 'a'; i <= 'z'; i++)
    {
        ans -= a[i] * (a[i] - 1) / 2;
    }
    ans += n * (n - 1) / 2;
    printf("%lld\n", ans + 1);
    return 0;
}
