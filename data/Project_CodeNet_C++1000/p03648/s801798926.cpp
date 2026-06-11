#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const int MAXN=2e5+100;
const double eps=1e-10;
int main()
{
    LL k,n=50;
    while(scanf("%lld",&k)!=EOF)
    {
        printf("50\n");
        LL cnt=k/50,res=k%50;
        for(int i=0;i<50;i++)
        {
            if(i<res)
            printf("%lld",i+cnt+n-res+1);
            else printf("%lld",i+cnt-res);
            if(i!=49) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
