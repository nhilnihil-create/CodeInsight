// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define int long long
#define mpr make_pair 
typedef long long ll;
#pragma GCC optimize("Ofast")

const int maxn = 1e6+10;
const int mod = 998244353;
const int inf = 1e18+10;

int n;
int a[maxn];

signed main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n;
    int sm = 0, m = n*(n+1)/(2ll);
    for(int i = 1; i <= n; i++)
    {
        cin>> a[i];
        sm += a[i];
    }
    if(sm%m != 0) return cout<<"NO", 0;
    int k = sm/m;

    a[0] = a[n];
    for(int i = 1; i <= n; i++)
        if((((a[i]-a[i-1])%n+n)%n != k%n) || (a[i]-a[i-1]-k) > 0)
            return cout<<"NO", 0;
    cout<<"YES";
}


