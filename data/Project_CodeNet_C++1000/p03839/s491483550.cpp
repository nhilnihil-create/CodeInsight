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
        int n,k;
        cin>>n>>k;
        vector<int>v(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
        }
        vector<int>fp(n+2,0);
        vector<int>bp(n+2,0);
        for(int i=1;i<=n;i++)
        {
            if(v[i]>0)
            {
                fp[i]=bp[i]=v[i];
            }
        }
        for(int i=1;i<=n+1;i++)
        {
            fp[i]+=fp[i-1];
        }
        for(int i=n;i>=0;i--)
        {
            bp[i]+=bp[i+1];
        }
        for(int i=1;i<=n;i++)
        {
            v[i]+=v[i-1];
        }
        int ans=0;
        int i=k;
        for(i=k;i<=n;i++)
        {
            ans=max(ans,v[i]-v[i-k]+fp[i-k]+bp[i+1]);
        }
        for(int i=k;i<=n;i++)
        {
            ans=max(ans,fp[i-k]+bp[i+1]);
        }
        cout<<ans<<endl;
    }