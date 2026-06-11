// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define int long long
#define mpr make_pair 
#define pii pair<int,int>
typedef long long ll;
#pragma GCC optimize("Ofast")

const int maxn = 2e5+10;
const int mod = 998244353;
const int inf = 1e9+10;

int n, m;
int p[maxn], q[maxn];

signed main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>> n;
    for(int i = 1; i <= n; i++)
    {
        cin>> p[i];
        q[p[i]] = i;
    }

    for(int i = 1; i <= n; i++)
        cout<< q[i] + (n+1) * i <<" ";
    cout<<"\n";
    for(int i = 1; i <= n; i++)
        cout<< (n+1) * (n+1) - (n+1) * i <<" ";
}

 



