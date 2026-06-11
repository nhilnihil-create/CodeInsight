
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define LL long long
#define N 100005
#define INF 0x3f3f3f3f
const double esp = 1e-6;
const LL Mod = 1e9+7;
LL a[N];
void init()
{
    LL sum = 1;
    for(int i = 1; i < N; i++)
    {
        sum = ((LL)i*sum)%Mod;
        a[i] = sum;
        //printf("%lld\n",a[i]);
    }
}
int b[N];
int main()
{
    init();
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 1; i <= n; i++)
            scanf("%d",&b[i]);
        LL sum = 1;
        int k = 1;
        int i;
        for(i = 1; i <= n; i++)
        {
            int i1 = i;
            int k1 = k;
            while(b[i1--] < 2*(i-k))
                k++;
            if(b[i1+1] == 2*(i-k) && i != n)
                k++;
            if(k1 < k)
                sum = (sum*(i-k+2))%Mod;
            //printf("%d  %d  %d\n",b[i],k,2*(i-k)+1);
            //printf("%lld\n",sum);
        }
        sum = (sum*(n-k+1))%Mod;
        sum = sum*a[n-k]%Mod;
        printf("%lld\n",sum);
    }
    return 0;
}
