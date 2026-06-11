#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
long long int n,A,B;
int a[100001];
int ff(int p)
{
    long long int i;
    long long int sum,t=0;
    for(i=0; i<n; i++)
    {
        sum=a[i]-p*B;
        if(sum>0)
        {
         t+=(int)ceil(sum*1.0/(A-B));
            if(t>p||t<0)
                return false;
        }
    }
     return true;
}
int main()
{
    cin>>n>>A>>B;

        int maxn=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            maxn=max(maxn,a[i]);
        }
      long long  int l=0,r,h;
        h=maxn;
        while(l<h)
        {
            r=(l+h)/2;
            if(ff(r))
                h=r;
            else l=r+1;
        }
        cout<<l<<endl;

    return 0;
}
