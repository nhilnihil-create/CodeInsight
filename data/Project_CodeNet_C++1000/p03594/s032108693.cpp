#include <bits/stdc++.h>
using namespace std;
const char s[5]="RYGB";
int h,w,d;
char res[505][505];
int main()
{
    scanf("%d%d%d",&h,&w,&d);
    for (int i=0;i<h;++i)
        for (int j=0;j<w;++j) {
            int x=(i+j)/d,y=(i-j+w-1)/d;
            res[i][j]=s[(x&1)*2+(y&1)];
        }
    for (int i=0;i<h;++i)
        puts(res[i]);
    return 0;
}
