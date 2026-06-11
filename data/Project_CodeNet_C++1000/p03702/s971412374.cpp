#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
const int maxn = 1e6+100;
const int MOD = 1e9+7;
const double Pi = 3.141592654;
typedef long long ll;
typedef unsigned long long ull;

int n;
ll a, b;
ll h[maxn];

bool Judge(ll u)
{
    ll t = u*b;
    ll d = a-b;
    ll sum = 0;
    for(int i=n ; i>=1 ; --i)
    {
        if(h[i] > t)
        {
            if((h[i]-t)%d) sum += (h[i]-t)/d+1;
            else sum += (h[i]-t)/d;
        }
    }
    if(sum <= u) return 1;
    return 0;
}

int main()
{
    cin >> n;
    cin >> a >> b;
    ll r = 0, l = 1;
    for(int i=1 ; i<=n ; ++i)
    {
        cin >> h[i];
        r += h[i]/b+1;
    }
    sort(h+1, h+1+n);
    while(l < r)
    {
        ll m = (l+r)>>1;
        if(Judge(m)) r = m;
        else l = m+1;
    }
    cout << l << endl;
}
