#include<cstdio>
#include<functional>
#include<algorithm>

const int N=100005;

int n,a[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    std::sort(a+1,a+1+n,std::greater<int>());
    for(int i=1;i<=n;++i)
    {
        if(a[i+1]<i+1)
        {
            int ans=0;
            for(int j=i+1;a[j]==i;++j)ans^=1;
            ans|=(a[i]-i)&1;
            if(ans)puts("First");
            else puts("Second");
            return 0;
        }
    }
}