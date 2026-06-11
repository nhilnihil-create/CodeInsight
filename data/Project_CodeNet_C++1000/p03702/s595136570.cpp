#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<math.h>
#include<queue>
#define inf 0x3f3f3f
#define M 100000000
#define ll  long long
using namespace std;
ll x[M],p[M];
ll n,a,b;
bool judge(ll y)
{
    ll sum=0;
    ll t;
    for(int i=0;i<n;i++)
    {
        t=(ll)x[i]-b*y;
        if(t>0)
        {
            sum=sum+(ll)ceil(t*1.0/(a-b));
            if(sum>y||sum<0)
                return false;
        }
    }
    return true;
}
int fin()
{
    sort(x,x+n);
    ll mid,c,d;
    c=x[n-1]/a+1;
    d=x[n-1]/b+1;
    while(c<d)
    {
        mid=(c+d)/2;
        if(judge(mid))
            d=mid;
        else
            c=mid+1;
    }
    cout<<c<<endl;
}
int main()
{

    cin>>n>>a>>b;
    int i,j;
    for(i=0; i<n; i++)
        cin>>x[i];
    fin();
    return 0;
}


