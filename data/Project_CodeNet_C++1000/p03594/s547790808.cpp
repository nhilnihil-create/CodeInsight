#include<bits/stdc++.h>
using namespace std;
int h,w,d;
int mp[2005][2005];
void ran()
{
    for(int i=0;i<=2000;i++)
    {
        for(int j=0;j<=2000;j++)
        {
            int tmp=((i/(d))%2)*2+(j/(d))%2;
            mp[i][j]=tmp;
     //      cout<<tmp<<endl;
        }
    }
}
int main()
{
    cin>>h>>w>>d;
    ran();
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            int x=i+j+500,y=i-j+500;
            if(mp[x][y]==0)putchar('R');
            else if(mp[x][y]==1)putchar('Y');
            else if(mp[x][y]==2)putchar('G');
            else putchar('B');
        }
        puts("");
    }
    return 0;
}
