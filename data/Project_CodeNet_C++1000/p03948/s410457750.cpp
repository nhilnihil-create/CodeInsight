#include<bits/stdc++.h>
using namespace std;
int arr[100005],mx[100005];
main()
{
	int t,p;
    scanf("%d%d",&t,&p);
    for(int i = 1;i <= t;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i = t;i >= 1;i--)
    {
        mx[i]=arr[i];
        if(i!=t)
        mx[i]=max(mx[i+1],mx[i]);
    }
    int ck1=-1e9,ck2=0;
    for(int i = 1;i < t;i++)
    {
        if(mx[i+1]-arr[i]>ck1)
        {
            ck1=arr[i]-mx[i+1];
            ck1=-ck1;
            ck2=1;
            //printf("%d %d %d\n",i,arr[i],mx[i]);
        }
        else if(mx[i+1]-arr[i]==ck1)
        {
            ck2++;
        }
    }
    printf("%d",ck2);
}
