#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
    }
    sort(a+1,a+n+1,cmp);
    a[0]=a[1];
    a[n+1]=0;
    int ans=0;
    while(a[ans+2]>=ans+2){
        ans++;
    }
    //printf("%d\n",ans);
    int x=a[ans+1]-ans;
    int y=ans;
    while(a[y]>=ans+1)
        y++;
    y=y-ans-1;
    //printf("%d %d\n",x,y);
    if(x%2==0||y%2==0){
        puts("First");
    }
    else{
        puts("Second");
    }
    return 0;
}
