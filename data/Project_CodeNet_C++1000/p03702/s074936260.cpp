#include <iostream>
using namespace std;
#include<string.h>
#include<set>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include <cstdio>
#include <cstdlib>
#include<stack>
#include<vector>
long long  a[51000000];
long long  n,a1,b1;
long  panduan(long long  zhi)
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
    //cout<<zhi<<"_"<<add<<endl;
    return add<=zhi;
}
int  main()
{
    cin>>n>>a1>>b1;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    long long  kaishi=0,jieshu=1e9;
    long long  mid;
    //cout<<panduan(3)<<"_"<<endl;
    int t;
    while(kaishi<jieshu-1)
    {
        //cout<<kaishi<<"_"<<jieshu<<endl;
        mid=(jieshu+kaishi)>>1;
        if(panduan(mid))
        {
            jieshu=mid;
            t=mid;
        }
        else
            kaishi=mid;
    }
    cout<<jieshu<<endl;
    return 0;
}