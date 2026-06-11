#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000005;
const int mod=998244353;
int n;
int a[N],z[N];
bool check(int x){
    for(int i=1;i<=2*n-1;i++)
        z[i]=a[i]>=x;
    for(int i=0;i<n-1;i++){
        if(z[n-i]==z[n-i-1])
            return z[n-i];
        if(z[n+i]==z[n+i+1])
            return z[n+i];
    }
    return z[1];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++)
        scanf("%d",&a[i]);
    int l=1,r=2*n;
    while(l+1<r){
        int mid=(l+r)>>1;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%d\n",l);
}
