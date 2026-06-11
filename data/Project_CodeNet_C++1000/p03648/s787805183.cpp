#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll K;
ll ans[100] = {0};

int main()
{
    scanf("%lld",&K);
    printf("50\n");
    for(int i = 0; i < 50; i++)
    {
        ans[i] += i + K / 50;
    }
    ll all = 0;
    for(int i = 0; i < K % 50; i++)
    {
        ans[i] += 51;
    }
    for(int i = 0; i < 50; i++)
    {
        printf("%lld",ans[i] - K % 50);
        if(i != 49)printf(" ");
    }printf("\n");
    return 0;
}
