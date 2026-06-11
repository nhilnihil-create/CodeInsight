#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

char tmp;
int len;

int main()
{
    int tmpp=1e9;
    printf("? %d\n",tmpp);
    fflush(stdout);
    scanf("\n");
    scanf("%c",&tmp);
    if(tmp=='Y')
    {
        int ask_num=1e9-1;
        int ans=1e9;
        len=9;
        while(1)
        {
            printf("? %d\n",ask_num);
            fflush(stdout);
            scanf("\n");
            scanf("%c",&tmp);
            if(tmp=='N')break;
            len--;
            ask_num/=10;
            ans/=10;
            if(ans==1)break;
        }
        printf("! %d",ans);
    }
    else
    {
        int ask_num=1e8;
        len=9;
        while(1)
        {
            printf("? %d\n",ask_num);
            fflush(stdout);
            scanf("\n");
            scanf("%c",&tmp);
            if(tmp=='Y')break;
            len--;
            ask_num/=10;
        }
        int l=1,r,mid;
        for(int i=1;i<len;i++)l*=10;
        r=l*10;r--;l+=1;
        while(l<r)
        {
            mid=(l+r)/2;
            long long cao=mid;
            cao*=10;
            printf("? %lld\n",cao);
            fflush(stdout);
            scanf("\n");
            scanf("%c",&tmp);
            if(tmp=='Y')r=mid;
            else l=mid+1;
        }
        printf("! %d",l);
    }
    return 0;
}
