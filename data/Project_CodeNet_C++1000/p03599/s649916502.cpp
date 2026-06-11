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
 
const int S=3123;
bool sugar_can[S+5];
bool water_can[S+5];

bool Is_max(int sugar,int water_sugar,int s,int ws)
{
    if(sugar*ws<s*water_sugar)return true;
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    #endif
    int a,b,c,d,e,f;
    while(sf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)==6)
    {
        memset(sugar_can,false,sizeof sugar_can);
        memset(water_can,false,sizeof water_can);
        for(int i=0;i<=f;i++)
        {
            for(int j=0;j<=f;j++)
            {
                if(i*c+j*d<=f)sugar_can[i*c+j*d]=true;
                if(i*100*a+j*100*b<=f)water_can[i*100*a+j*100*b]=true;
            }
        }

        int water_sugar=100*a,sugar=0;
        for(int w=100*a;w<=f;w++)
        {
            if(water_can[w])
            {
                int s=(e*w)/100;
                for(int i=s;i>=0;i--)
                {
                    if(sugar_can[i] && w+i<=f)
                    {
                        if(Is_max(sugar,water_sugar,i,w+i))
                        {
                            water_sugar=w+i;
                            sugar=i;
                        }
                    }
                }
            }
        }
        pf("%d %d\n",water_sugar,sugar);
    }
    return 0;
}
 









 


























