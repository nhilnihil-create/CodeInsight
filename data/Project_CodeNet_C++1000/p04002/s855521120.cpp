#include<cstdio>
#include<cstring>
#include<utility>
#include<set>
using namespace std;
typedef pair<int,int> p;
set<p> map;
long long num[10];
int h,w,n,a,b;
int count(int x,int y)
{
    int num=0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int nx=x+i,ny=y+j;
            if(0<nx&&nx<=h&&0<ny&&ny<=w)
            {
                if(map.count(p(nx,ny)))
                    num++;
            }
            else
                return 0;
        }
    }
    return num;
}
void check(int x,int y)
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int temp=count(x+i,y+j);
            if(temp)
            {
                num[temp-1]--;
                num[temp]++;
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&h,&w,&n);
    num[0]=(long long)(h-2)*(w-2);
    while (n--)
    {
        scanf("%d%d",&a,&b);
        map.insert(p(a,b));
        check(a,b);
    }
    for (int i = 0; i < 9; i++)
        printf("%lld\n",num[i]);
    printf("%lld",num[9]);
}