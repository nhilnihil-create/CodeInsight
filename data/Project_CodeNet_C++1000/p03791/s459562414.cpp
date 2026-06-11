#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const long long int mod=1e9+7;
int N;
int main()
{
   // freopen("in.txt","r",stdin);
    while(scanf("%d",&N)==1)
    {
        int x;
        long long int ans=1;
        int bad=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&x);
            ans=(ans*(i+1-bad))%mod;
            if(x<(i-bad)*2+1)
                bad++;
        }
        printf("%I64d\n",ans);
    }


    return 0;
}


