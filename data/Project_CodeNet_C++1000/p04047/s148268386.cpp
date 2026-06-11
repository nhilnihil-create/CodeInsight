#include <stdio.h>
#include <algorithm>


int main()
{
    int n;
    int l[200];
    scanf("%d",&n);
    for(int i=0;i<2*n;i++) scanf("%d",&l[i]);
    std::sort(l,l+2*n);
    int ans=0;
    for(int i=0;i<2*n;i+=2)
    ans+=l[i];
    printf("%d\n",ans);
}