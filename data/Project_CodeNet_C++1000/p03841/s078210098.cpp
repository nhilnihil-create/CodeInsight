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
    int n;
    cin>>n;
    int a[n+1];
    set<int>s;
    map<int,int>m;

    for(int i=0;i<n;i++){
        cin>>a[i+1];
        s.insert(a[i+1]);
        m[a[i+1]]=i+1;
    }
    int ans[n*n+1];
    for(int i=1;i<=n*n;i++)
        ans[i]=-1;
    bool flag=true;
    for(auto c:m)
    {
        int i=c.second;
        ans[a[i]]=i;
        int have_to=i-1;
        for(int j=1;j<=a[i]-1 && have_to>=1;j++)
        {
            if(ans[j]==-1 && !s.count(j))
            {
                ans[j]=i;
                have_to--;
            }
        }
        if(have_to!=0)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(auto c:m)
    {
        int i=c.second;
        int have_to=n-i;
        for(int j=a[i]+1;j<=n*n && have_to>=1;j++)
        {
            if(ans[j]==-1)
            {
                ans[j]=i;
                have_to--;
            }
        }
        if(have_to!=0)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<=n*n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}