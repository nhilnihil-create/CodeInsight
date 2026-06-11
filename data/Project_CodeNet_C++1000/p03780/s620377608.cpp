#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[5009];
int a[5009];
ll sum=0;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=min(a[i],k);
        a[i]=min(a[i],k);//这里可以自己验证一下，如果a[i]>k,令a[i]=k没有影响。否则如果a[i]>k不能传递。

    }
    sort(a+1,a+1+n);
    f[0]=1;
    for(int i=n;i>=0;i--)
    {
        int flag=1;
        for(int j=k-1;j>=k-sum&&j>=0;j--)
        {
            if(f[j])
            {
                flag=0;
            }
        }
        if(flag)
        {
            cout<<i<<endl;
            return 0;
        }
        for(int j=k-1;j>=a[i];j--)f[j]|=f[j-a[i]];//因为从i这个位置向前移动了一位，所以只要看j-a[i]是否出现了。
        sum-=a[i];
    }
}