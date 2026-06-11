#include<bits/stdc++.h>
using namespace std;
int n,num,maxn,ans=1,minn,a[100001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    minn=a[1],maxn=a[n];
    if(minn<maxn-1||maxn>=n)ans=0;
    if(maxn==minn)
    {
        if(minn+1!=n&&minn*2>n)ans=0;
    }
    else
    {
        for(int i=1;i<=n;i++)if(a[i]==minn)num++;
        n-=num;maxn-=num;
        if(minn<num)ans=0;
        else if(maxn*2>n)ans=0;    
    }
    if(ans)cout<<"Yes";
	else cout<<"No";
    return 0;
}