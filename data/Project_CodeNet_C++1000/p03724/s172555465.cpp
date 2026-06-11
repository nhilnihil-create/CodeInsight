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

int n, m;
bool is[maxn];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n >> m;
    for(int i = 1, x; i <= 2*m; i++)
    {
        cin>> x;
        is[x] ^= 1;
    }

    for(int i = 1; i <= n; i++)
        if(is[i]) return cout<<"NO", 0;
    cout<<"YES";
}



