#include <bits/stdc++.h>

#define int long long
#define counter(m)     for(int i=0;i<m;i++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
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
    vector<int>v(n+1);
    v[0]=-1;
    for(int i=0;i<n;i++)
    {
        cin>>v[i+1];
    }
    sort(v.begin(),v.end());
    int sum=v[1];
    int idx=-1;
    for(int i=2;i<=n;i++)
    {
       if(v[i]>2*sum)
       {
           idx=i;
       }
       sum+=v[i];
    }
    if(idx==-1)
        cout<<n<<endl;
    else
        cout<<n-idx+1<<endl;
    return 0;
}