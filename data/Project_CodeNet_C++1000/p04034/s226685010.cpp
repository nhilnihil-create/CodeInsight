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
    set<int>s;
    int n,m;
    cin>>n>>m;
    s.insert(1);
    vector<int>num_of_balls(n+1,1);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        if(s.count(a))
        {
            s.insert(b);
            num_of_balls[b]++;
            num_of_balls[a]--;
            if(num_of_balls[a]==0)
                s.erase(a);
        }
        else{
            num_of_balls[a]--;
            num_of_balls[b]++;
        }
    }
    cout<<s.size()<<endl;
    return 0;
}