#include<cstdio>
#include<cstring>
int a[2001000];
int b[2001000];
int n,L;
void turn(int x)//<=x的是0，>x的是1
{
    for(int i=1;i<=L;i++)
        if(a[i]<=x)
            b[i]=0;
        else
            b[i]=1;
}
int main()
{
    scanf("%d",&n);
    L=(n<<1)-1;
    for(int i=1;i<=L;i++)
        scanf("%d",&a[i]);
    int l=1,r=L,mid;
    while(l<r)
    {
        int flag=0;
        mid=(l+r>>1);
        turn(mid);
        for(int i=1;i<n;i++)
        {
            if(b[n+i]==b[n+i-1])
            {
                if(b[n+i]==0)
                    r=mid;
                else
                    l=mid+1;
                flag=1;
                break;
            }
            if(b[n-i]==b[n-i+1])
            {
                if(b[n-i]==0)
                    r=mid;
                else
                    l=mid+1;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            if(b[n]^(n&1)^1)
                l=mid+1;
            else
                r=mid;
        }
    }
    printf("%d\n",l);
    return 0;
}
