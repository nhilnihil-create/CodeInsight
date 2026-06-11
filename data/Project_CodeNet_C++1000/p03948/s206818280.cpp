#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    int x,pre;
    int minn,maxx=-999;
    int cnt=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(i)
        {
            if(x>pre)
                if(x-minn>maxx)
                    maxx=x-minn,cnt=1;
                else if(x-minn==maxx)
                    cnt++;
            if(minn>x)
                minn=x;
        }
        else
            minn=x;
        pre=x;
    }
    printf("%d\n",cnt);
}
