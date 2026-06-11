#include <bits/stdc++.h>
#define endl '\n'
#define modulo 1000000007
#define int int64_t
//#pragma GCC optimize("trapv")
#define float double
#define PI acos(-1);
#define sinDegrees(x) sin((x) * PI / 180.0)
#define tanDegrees(x) tan((x) * PI / 180.0)
#define atanDegrees(x) atan(x)* 180.0 / PI
using namespace std;
int power(int x,int y,int m)
{
int temp;
if(y == 0)
return 1;
temp = (power(x, y/2,m))%m;
if (y%2 == 0)
return ((temp%m)*temp);
else
return ((x*temp%m)*temp%m)%m;
}
int inv(int x)
{
return (power(x,modulo-2,modulo))%modulo;
}
bool comp(int a,int b)
{
return a<b;
}
///Solution created by:Ahmadsm2005
int32_t main()
{
//freopen("output.txt","w", stdout);
//freopen("output.txt","r", stdin);
//iostream::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int n,k,x,y,counter=0;
cin>>n>>k>>x>>y;
for(int i=1;i<=n;i++)
if(i<=k)
counter+=x;
else
counter+=y;
cout<<counter;
return 0;
}
