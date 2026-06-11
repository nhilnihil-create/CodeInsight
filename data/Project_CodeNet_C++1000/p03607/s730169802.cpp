#include <bits/stdc++.h>
#include <cstring>
#include <ctype.h>
#include<stdlib.h>

#define flin            freopen("input.txt", "r", stdin);
#define flout           freopen("output.txt", "w", stdout);
#define ll              long long
#define ull             unsigned long long
#define fastio          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define nl              '\n'
#define nll             '\0'
#define pb              push_back
#define bdyptb          return 0;
#define sorted(x)       sort(x.begin(), x.end())
#define reversed(x)     reverse(x.begin(), x.end())
#define all(x)          x.begin(), x.end()
#define mset(a, b)        memset(a, b, sizeof(a));
#define testcase        ll t,tt; cin>>tt; for(t=1;t<=tt;t++)

#define pi acos(-1.00)
#define mx 1000007

using namespace std;
ull ncr(ull n, ull r)
{
    ull p = 1, k = 1;

    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            ull m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}

int main()
{
    fastio;
    int n;
    cin>>n;
    map<int, int> mp;
    map<int, int>::iterator it;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    int ans=0;
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        ans+=it->second % 2;
    }

    cout<<ans<<nl;

}
