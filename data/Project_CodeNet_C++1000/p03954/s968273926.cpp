#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200005;
typedef long long ll;
int n,a[N];
int z[N];
bool check(int x){
    for(int i=1;i<=2*n-1;i++){
        z[i]=a[i]>=x;
    }
    for(int i=0;i<n-1;i++){
        int s0=0,s1=0;
        if(z[n-i]==1&&z[n-i-1]==1)
            return 1;
        if(z[n-i]==0&&z[n-i-1]==0)
            return 0;
        if(z[n+i]==1&&z[n+i+1]==1)
            return 1;
        if(z[n+i]==0&&z[n+i+1]==0)
            return 0;
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
