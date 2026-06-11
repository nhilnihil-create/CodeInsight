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
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;

int32_t main() {
    nitin;
    int n;
    cin>>n;
    string a;
    string b;
    cin>>a>>b;
    int ans=2*n;
    for(int i=n-1;i>=0;i--)
    {
        int j=0;
        int ti=i;
        bool flag=true;
        for(;j<=n-1 && ti<=n-1;j++,ti++)
        {
            if(a[ti]!=b[j])
                flag=false;
        }
        if(flag)
        ans=min(ans,2*n-(n-i));
    }
    cout<<ans<<endl;
}