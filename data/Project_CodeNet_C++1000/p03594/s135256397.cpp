#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;
char color[5] = "RYGB";
char res[MAXN][MAXN];

int main()
{
    int h,w,d,x,y;
    scanf("%d %d %d",&h,&w,&d);
    for(int i = 1 ;i <= h; ++i)
    {
        for(int j = 1; j <= w; ++j)
        {
            //先转化成切比雪夫距离
            x = (i+j+500)/d;
            y = (i-j+500)/d;
            //然后再根据切比雪夫距离来判断颜色
            res[i][j] = color[(x%2)*2+y%2];
            putchar(res[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
