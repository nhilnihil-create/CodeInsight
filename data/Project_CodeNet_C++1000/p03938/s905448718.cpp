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
    vector<int>v(n);
    map<int,int>m;
    for(int i=0;i<n;i++){
        cin>>v[i];
        m[v[i]]=i+1;
    }
    for(int i=1;i<=n;i++)
        cout<<30000*i<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<30000*(n-i)+m[i]<<" ";
    }
    cout<<endl;
    return 0;
}