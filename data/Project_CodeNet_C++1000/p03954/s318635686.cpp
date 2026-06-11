#include <cstdio>
const int N=2e6+10;
int a[N],d[N],n;
bool check(int m)
{
    for(int i=1;i<n<<1;i++) d[i]=a[i]>m;
    int l=-1,r=-1;
    for(int i=n-1;i;i--)
    {
        if(d[i]^d[i+1]) continue;
        l=i;break;
    }
    for(int i=n+1;i<n<<1;i++)
    {
        if(d[i]^d[i-1]) continue;
        r=i;break;
    }
    if((!~l)&&(!~r)) return d[n]^(n-1&1);
    if(!~l) return d[r];
    if(!~r) return d[l];
    return n-l>r-n?d[r]:d[l];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n<<1;i++) scanf("%d",a+i);
    int l=1,r=(n<<1)-1;
    while(l<r)
    {
        int mid=l+r>>1;
        if(check(mid))
            l=mid+1;
        else
            r=mid;
    }
    printf("%d\n",l);
    return 0;
}