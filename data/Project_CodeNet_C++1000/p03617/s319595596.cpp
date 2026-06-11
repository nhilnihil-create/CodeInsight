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
    //0.25,0.5,1,2
    int q,h,s,d;
    cin>>q>>h>>s>>d;
    int n;
    cin>>n;
    int m=min(8*q,min(4*h,min(2*s,d)));
    int ans=(n/2)*m;
    ans+=(n%2)*(min(4*q,min(2*h,s)));
    cout<<ans<<endl;

    return 0;
}