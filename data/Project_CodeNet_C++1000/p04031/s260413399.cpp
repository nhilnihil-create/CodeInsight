#include <iostream>
#include<cmath>
#include<vector>
#include<tuple>
#include <ctime>
#include<algorithm>
#include <initializer_list>
#include <cstring> 
#include <queue>

using namespace std;
 
#define tii tuple<int,int>
#define vi vector<int>
#define vii vector<vi>
#define ll long long
#define vl vector<ll>
#define vll vector<vl>
 
#define mymod 1000000007
#define sz 200002

ll power(ll a, ll b, ll p)
{
    if(a<2)
    return a;
    ll ans = 1;
    while(b)
    {
        if(b%2)
        {
            ans *= a;
            ans %= p;
        }
        b = b/2;
        a = (a*a)%p;
    }
    return ans;
}

ll mgcd(ll a, ll b)
{
    if(a==0)
        return b;
    return mgcd(b%a,a);
}

int main() {
    clock_t tstart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Start
    int n;
    cin>>n;
    vi v(n);
    int mn = mymod;
    int mx = -mymod;
    for(auto &x: v){
        cin>>x;
        mx = max(mx,x);
        mn = min(mn,x);
    }
    int ans = mymod;
    for(int i=mn;i<=mx;i++) {
        int s = 0;
        for(auto x:v) s += (i-x)*(i-x);
        ans = min(ans,s);
    }
    cout<<ans;
    // cout<<"\n\nTotal Time Taken : "<<(double)(-tstart + clock())/CLOCKS_PER_SEC<<"sec\n\n";
    return 0;
}
 
