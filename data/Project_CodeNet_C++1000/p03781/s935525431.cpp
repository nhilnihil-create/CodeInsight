#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
//    freopen("f.in","r",stdin);
//    freopen("f.out","w",stdout);
    long long x,n;
    scanf("%I64d",&x);
    n=(sqrt((8*x+1))-1)/2;
    if((2*n+1)*(2*n+1)<(8*x+1))
        n++;
    printf("%I64d\n",n);
    return 0;
}
