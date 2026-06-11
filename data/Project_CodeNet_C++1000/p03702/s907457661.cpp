#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include <cstdlib>
using namespace std;
long long  a[200000];
long long  n,a1,b1;
long  check(long long  zhi)
{
    long long  t=b1*zhi;
    long long  add=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]-t>0)
        {
            if((a[i]-t)%(a1-b1)==0)
                add+=(a[i]-t)/(a1-b1);
            else
                add+=(a[i]-t)/(a1-b1)+1;
        }
    }
    return add<=zhi;
}
int  main()
{
    cin>>n>>a1>>b1;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    long long  st=0,en=1e9;
    long long  mid;
    int t;
    while(st<en-1)
    {
        mid=(en+st)>>1;
        if(check(mid))
        {
            en=mid;
            t=mid;
        }
        else
            st=mid;
    }
    cout<<en<<endl;
    //system("pause");
    return 0;
}
