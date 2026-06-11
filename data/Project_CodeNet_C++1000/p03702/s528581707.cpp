#include <iostream>
#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;
LL n,a,b,h[100050];
bool judge(LL x)
{
    LL S=x*b;
    LL M=a-b;
    LL sum=0;
    for(int i=n-1;i>=0;i--)
    {
        if(h[i]>S)
        {
           if((h[i]-S)%M)
             sum+=(h[i]-S)/M+1;
            else
             sum+=(h[i]-S)/M;
        }

    }
    if(sum<=x)
        return true;
    return false;
}
int main()
{
    scanf("%lld %lld %lld",&n,&a,&b);
      LL  max1=0;
        for(int i=0;i<n;i++)
        {
          cin>>h[i];
          max1+=h[i]/b+1;
        }
       LL head=1;
        sort(h,h+n);
        while(head<max1)
        {
            LL mid=(max1+head)/2;
            if(judge(mid))
                max1=mid;
            else
                head=mid+1;
        }
        cout<<head<<endl;
    return 0;
}
