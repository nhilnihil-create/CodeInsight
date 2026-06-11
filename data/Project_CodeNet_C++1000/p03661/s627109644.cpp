#include <bits/stdc++.h>

using namespace std;

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)
#define SCANFD(x) scanf("%d",&x)

int main(){    
    int N;
    int a[200000];
    long long x,y;
    long long res;

    scanf("%d",&N);

    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);
    
    x=a[0];
    y=0;
    for(int i=1;i<N;i++)
        y+=a[i];
    
    res = abs(x-y);

    for(int i=1;i<N-1;i++){
        x+=a[i];
        y-=a[i];
        res = min(res,abs(x-y));
    }

    printf("%lld\n",res);
    
    return 0;
}
