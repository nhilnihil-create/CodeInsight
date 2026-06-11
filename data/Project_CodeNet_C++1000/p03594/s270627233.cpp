#include <bits/stdc++.h>
using namespace std;

char color[5] = "RYGB";

int main()
{
    int h,w,d,x,y;
    scanf("%d %d %d",&h,&w,&d);
    for(int i = 1 ;i <= h; ++i)
    {
        for(int j = 1; j <= w; ++j)
        {
            //映射坐标，+500是防止出现负数，都+500是保持俩数的奇偶性不变
            x = (i+j+500)/d;
            y = (i-j+500)/d;
            //根据坐标奇偶性来判断颜色
            putchar(color[(x%2)*2+y%2]);
        }
        putchar('\n');
    }
    return 0;
}
