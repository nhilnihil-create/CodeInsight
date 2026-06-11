#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long n,i,d,dd,x,y,sum=0;
    cin>>n;
    long long a[n+2];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    x=a[0];
    y=sum-a[0];
    d=abs(x-y);
    for(i=1;i<n-1;i++)
    {
        x+=a[i];
        y-=a[i];
        dd=abs(x-y);
        if(dd<d)
        {
            d=dd;
        }

    }
    cout<<d<<endl;
    return 0;
}
