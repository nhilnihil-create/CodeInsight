#include <bits/stdc++.h>

#define int long long
#define ci(m)     for(int i=0;i<m;i++)
#define cj(m)     for(int j=0;j<m;j++)
#define ck(m)     for(int k=0;k<m;k++)
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
    vector<int>v(n);
    for(auto &c:v) cin>>c;
    sort(v.begin(),v.end());
    int l=0;
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        sum+=v[i];
        if(2*sum>=v[i+1])
            continue;
        else
            l=i+1;
    }
    cout<<n-l<<endl;
    return 0;
}