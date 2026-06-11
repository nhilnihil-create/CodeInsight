#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200;
int map[maxn][maxn];
int col[maxn * maxn];
int h,w,n;
int main(){
    scanf("%d %d",&h,&w);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",&col[i]);
    int ptr = 1;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if(col[ptr] <= 0)
                ptr++;
            if(i & 1){
                map[i][j] = ptr;
            }else{
                map[i][w + 1 - j] = ptr;
            }
            col[ptr]--;
        }   
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if(j - 1)
                printf(" ");
            printf("%d",map[i][j]);
        }
        printf("\n");   
    }
    return 0;
}