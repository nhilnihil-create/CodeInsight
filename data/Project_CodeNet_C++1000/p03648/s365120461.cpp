#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#define ll long long
using namespace std;
int main()
{
    ll K;
    while(scanf("%lld",&K)!=EOF)
    {
        printf("50\n");
        for(int i=0; i<50; i++)
        {
            if(i<K%50)
            {
                if(i==0)
                {
                    printf("%lld",K/50+50);
                }
                else
                {
                    printf(" %lld",K/50+50);
                }
            }
            else
            {
                if(i==0)
                {
                    printf("%lld",K/50+50-K%50-1);
                }
                else
                {
                    printf(" %lld",K/50+50-K%50-1);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
