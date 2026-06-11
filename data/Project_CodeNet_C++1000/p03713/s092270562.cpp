#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//#include <functional> // for less
#define PI acos(-1.0)
#define eps 1e-9
#define ll long long
#define ull unsigned long long
#define nl printf("\n")
#define sf scanf
#define pf printf
#define INF (ll)1e15
#define mod 1000000007

///#define isValid(n,m,nx,ny)nx>=0&&nx<n&&ny>=0&&ny<m
///int kx[]={1, 1, -1, -1, 2, 2, -2, -2}; //knight moves
///int ky[]={2,-2,  2, -2, 1,-1,  1, -1}; //knight moves
///int dx[]={1,-1,0,0,1,-1,1,-1};//eight direction
///int dy[]={0,0,1,-1,1,-1,-1,1};//eight direction
 
///using namespace __gnu_pbds;
using namespace std;
 
///inline double toRad(double deg){return deg*PI/180;}
///inline double toDeg(double rad){return rad*180/PI;}
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

typedef pair<ll,ll>ii; 
const int S=123456;

ll Solve(ll h,ll w)
{
    ll ans=INF;
    for(ll i=1;i<=h;i++)
    {
        ll j=(h-i)/2;
        ll k=(h-i)/2;
        if((h-i)%2)k++;
        ll mx=max({i*w,j*w,k*w});
        ll mn=min({i*w,j*w,k*w});
        ans=min(ans,mx-mn);

        j=w/2;
        k=w/2;
        if(w%2)k++;
        mx=max({i*w,j*(h-i),k*(h-i)});
        mn=min({i*w,j*(h-i),k*(h-i)});
        ans=min(ans,mx-mn);
    }    
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    #endif
    ll h,w;
    while(sf("%lld %lld",&h,&w)==2)
    {
        ll ans=Solve(h,w);
        ans=min(ans,Solve(w,h));
        pf("%lld\n",ans);
    }
    return 0;
}
 









 


























