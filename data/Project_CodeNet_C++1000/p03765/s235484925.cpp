#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

string s1, s2;
ll a[100005], b[100005];
ll q;

int main()
{
    cin>>s1>>s2>>q;
    s1 = ' ' + s1, s2 = ' ' + s2;
    for(ll i = 1; i < s1.size(); i++)
    {
        a[i] = a[i - 1];
        if(s1[i] == 'A') a[i]++;
        else a[i] += 2;
    }
    for(ll i = 1; i < s2.size(); i++)
    {
        b[i] = b[i - 1];
        if(s2[i] == 'A') b[i]++;
        else b[i] += 2;
    }
    while(q--)
    {
        ll t1, t2, t3, t4;
        scanf("%lld%lld%lld%lld", &t1, &t2, &t3, &t4);
        t1--, t3--;
        if((a[t2] - a[t1]) % 3 == (b[t4] - b[t3]) % 3) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
