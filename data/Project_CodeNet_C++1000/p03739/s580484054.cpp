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
 
const int S=123456;
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    #endif
    int n;
    while(sf("%d",&n)==1)
    {
        ll ara[n+5];
        for(int i=0;i<n;i++)
        {
            sf("%lld",&ara[i]);
        }

        ll psum,nsum,pans,nans;
        psum=nsum=pans=nans=0;
        for(int i=0;i<n;i++)
        {
            //pos-neg
            psum+=ara[i];
            if(i%2==0 && psum<=0)
            {
                pans+=abs(1-psum);
                psum=1;
            }
            else if(i%2==1 && psum>=0) 
            {
                pans+=abs(-1-psum);
                psum=-1;
            }

            //neg-pos
            nsum+=ara[i];
            if(i%2==0 && nsum>=0)
            {
                nans+=abs(-1-nsum);
                nsum=-1;
            }
            else if(i%2==1 && nsum<=0)
            {
                nans+=abs(1-nsum);
                nsum=1;
            }
            //pf("%lld %lld\n",pans,nans);
        }
        pf("%lld\n",min(pans,nans));
    }
    return 0;
}
 









 


























