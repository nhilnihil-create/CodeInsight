#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
char s[10];
void query(ll  x)
{
    printf("? %lld\n",x);
    fflush(stdout);
    scanf("%s",s);
}
int main()
{
    int x=1000000000;
    query(x);
    if(s[0]=='Y')
    {
        for(int i=9;i>=1;i--)
        {
            query(x-1);
            if(s[0]=='N')  break;
            x/=10;   
        }
        printf("! %d\n",x);
        return 0;
    }
    for(int i=9;i>=1;i--)
    {
        x/=10;
        query(x);
        if(s[0]=='Y')  break;
    }
    int l=x+1,r=x*10-1,ans;
    while(l<=r)
    {
        ll mid=((l+r)>>1);
        query(mid*10);
        if(s[0]=='Y')  r=mid-1,ans=mid;
        else           l=mid+1;
    }
    printf("! %d\n",ans);
    return 0;
}