#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int a[100010];
int main()
{
    register int n;
    cin>>n;
    for(register int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    for(register int i=1;i<=n;++i)
        if(i+1>a[i+1])
        {
            register int ans=0;
            for(register int j=i+1;a[j]==i;++j)
                ans^=1;
            ans|=(a[i]-i)&1;
            if(ans)
                puts("First");
            else 
                puts("Second");
            return 0;
        }
}