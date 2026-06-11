#include <bits/stdc++.h>
using namespace std;

char a[110][110];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h,w;
    cin>>h>>w;

    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>a[i][j];

    for(int i=0;i<w+2;i++)printf("#");
    printf("\n");

    for(int i=0;i<h;i++)
    {
        printf("#");
        for(int j=0;j<w;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("#\n");
    }

    for(int i=0;i<w+2;i++)printf("#");
    printf("\n");

    return 0;
}
