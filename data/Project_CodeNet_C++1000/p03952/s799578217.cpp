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

int n, x;
int a[maxn];

signed main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>> n >> x;
    if(x == 1 || x == 2*n-1) return cout<<"No", 0;
    
    a[n-1] = x-1; a[n] = x; a[n+1] = x+1;
    int L = 1;
    cout<<"Yes\n";
    for(int i = 1; i <= 2*n-1; i++)
    {
        if(!a[i])
        {
            if(L == x-1)
                L = x+2;
            a[i] = L++;
        }
        cout<< a[i] <<"\n";
    }
}

 



