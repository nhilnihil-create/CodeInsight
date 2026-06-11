#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,t) for(int i = s; i <= t; ++ i)
const int MaxN = 30;

int h, w, r, c;
char str[MaxN];

int main()
{
    scanf("%d%d",&r,&c);
    rep(i,1,r) rep(j,1,c)
    {
        scanf("%s",str);
        if(strcmp(str,"snuke") == 0)
            h = i, w = j;
    }
    printf("%c%d",(char)('A'+w-1),h);
    return 0;
}