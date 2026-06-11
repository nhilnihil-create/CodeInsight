//nupt2017team08
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <algorithm>
using namespace std;
int N,a;
const int mod = 1e9+7;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&N)!=EOF)
    {
        long long ans = 1;
        int k=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&a);
            k++;
            if(a<2*k-1)
            {
                ans*=k;
                ans%=mod;
                k--;
            }
        }
        for(int i=1;i<=k;i++)
        {
            ans*=i;
            ans%=mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
