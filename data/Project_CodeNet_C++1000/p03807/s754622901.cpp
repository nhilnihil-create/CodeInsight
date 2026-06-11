#include <stdio.h>

#define endl '\n'

int main()
{
    int n, i, o=0;
    scanf("%d", &n);

    while(n--)
    {
        scanf("%d", &i);
        o+=i&1;
    }

    o&1? printf("NO"): printf("YES");

    return 0;
}
