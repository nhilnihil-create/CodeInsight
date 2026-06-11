#include <stdio.h>
#include <string.h>

#define endl putchar('\n')

int main()
{
    int n, i;
    scanf("%d", &n);

    int a[n], b[n], c[n], p[n];
    c[0]=1;

    for(i=0; i<n; i++)
    {
        scanf("%d", &p[i]);
        if(i>0) c[i]=c[i-1]+n;
    }

    for(i=0; i<n; i++)
    {
        b[i]=c[i];
        a[i]=c[n-1-i];
    }

    for(i=0; i<n; i++) a[p[i]-1]+=i;

    for(i=0; i<n; i++) printf("%d ", b[i]);
    endl;
    for(i=0; i<n; i++) printf("%d ", a[i]);
    return 0;
}
