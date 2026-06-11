#include <cstdio>

int n,m,k;
const char s[]="RGBY";

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i,putchar('\n'))
        for(int j=0;j<m;++j)
            putchar(s[((m+i-j)/k&1)<<1|((m+i+j)/k&1)]);
    return 0;
}