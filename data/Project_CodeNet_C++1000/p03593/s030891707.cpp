#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll a[128];
ll n, m;
ll cnt2, cnt1;

int main()
{
    cin>>n>>m;
    for(ll i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        for(ll j = 0; j < m; j++)
        {
            a[s[j]]++;
        }
    }
    cnt1 = (n % 2) * (m % 2);
    cnt2 = (n % 2) * m / 2 + (m % 2) * n / 2;
    for(ll i = 'a'; i <= 'z'; i++)
    {
        a[i] %= 4;
        if(a[i] >= 2) cnt2--;
        if(a[i] % 2 == 1) cnt1--;
    }
    if(cnt2 >= 0 && cnt1 >= 0) printf("Yes\n");
    else printf("No\n");
    return 0;
}
