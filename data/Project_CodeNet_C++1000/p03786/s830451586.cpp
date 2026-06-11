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
const int N = 1e6+5;
const int mod = 998244353;
const int inf = 1e9+10;

int n, m, q;
int a[maxn], ps[maxn];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n;
    for(int i = 1; i <= n; i++) cin>> a[i];
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++) ps[i] = ps[i-1] + a[i];
    
    int ans = 0;
    for(int i = n-1; i >= 1; i--)
    {
        if(2*ps[i] < a[i+1]) return cout<< n-i, 0;
    }
    cout<< n;
}



