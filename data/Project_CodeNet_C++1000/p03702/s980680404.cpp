# include <bits/stdc++.h>
using namespace std;
long long int h[100000000];
long long int x[100000000];
 long long int n,a,b;
bool Sort(long long y)
{
    long long int sum=0;
    long long int t;
    for(int i=0;i<n;i++)
    {
        t=(long long)x[i]-y*b;
        if(t>0)
        {
            sum=sum+(long long int)ceil(t*1.0/(a-b));
            if(sum>y||sum<0)
                return false;
        }
    }
    return true;
}
void cazhao(long long x1[],long long n,long a1,long b1)
{
    sort(x1,x1+n);
  //  long long int sum=0;
    long long int  c;
    long long int  d;
    //  for(int i=0;i<n;i++)
    //   cout<<x1[i]<<" ";
    if(x1[n-1]%a1!=0)
        c=x1[n-1]/a1+1;
    else
        c=x1[n-1]/a1;
    if(x1[n-1]%b1!=0)
        d=x1[n-1]/b1+1;
    else
        d=x1[n-1]/b1;

   // cout<<x1[n-1]<<" ";
    while(c<d)
    {
        long long int mid=(c+d)/2;
           if(Sort(mid))
            d=mid;
           else
            c=mid+1;
    }
    //return c;
    cout<<c<<endl;
}
//cout<<d<<endl;
int main()
{

   while((scanf("%lld %lld %lld",&n,&a,&b)!=EOF))
    {int i;
    for(i=0; i<n; i++)
        scanf("%lld",&x[i]);
    cazhao(x,n,a,b);

    }
      return 0;
}
