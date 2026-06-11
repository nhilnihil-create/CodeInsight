#include <bits/stdc++.h>
#define int long long
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x,y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int modi(int a, int m)
{
    return power(a, m - 2, m);
}
int32_t main()
{
    nitin;
    vector<int>v(7);
    for(int i=0;i<7;i++){
        cin>>v[i];
    }
    int t=v[1];
    int x=v[3];
    int y=v[4];
    int z=v[0];
    int op2=0;
    int op1=(z/2)*4+t*2+(x/2)*4+(y/2)*4+6*(z%2 && y%2 && x%2);
    x--;
    y--;
    z--;
    if(x>=0 && y>=0 && z>=0)
    {
        op2=(6+(z/2)*4+t*2+(x/2)*4+(y/2)*4);
    }
    cout<<max(op1,op2)/2<<endl;
    return 0;
}