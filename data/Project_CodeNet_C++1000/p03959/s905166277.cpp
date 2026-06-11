#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 1000000007
using namespace std;
const int MAXN = 100005;
int n,a[MAXN],b[MAXN],limit[MAXN],sure[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        if(a[i]>a[i-1])limit[i]=1,sure[i]=a[i];
        else limit[i]=a[i];
    }
    for(int i=1;i<=n;++i)scanf("%d",b+i);
    for(int i=n;i>0;--i){
        if(b[i]>b[i+1]){
            if((sure[i] && b[i]!=sure[i]) || (!sure[i] && b[i]>limit[i])){puts("0");return 0;}
            limit[i]=1;
        }
        else limit[i]=min(limit[i],b[i]);
    }
    long long ans=1;
    for(int i=1;i<=n;++i)
        ans=ans*limit[i]%MOD;
    cout<<ans<<endl;
    return 0;
}