#include<cstdio>
using namespace std;

int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        int ans;
        if(a==b&&a==c)
            ans=1;
        else if(a!=b&&a!=c&&b!=c)
            ans=3;
        else
            ans=2;
        printf("%d\n",ans);
    }
    return 0;
}
