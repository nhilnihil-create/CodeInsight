#include <cstdio>
#include <algorithm>
#include <bitset>
#define MAXN 50005
#define MAXBS 70005
using namespace std;
bitset<MAXBS> bs;
int a[MAXN];
int main(void){
    int n,k;
    int ll,rr;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    sort(a+1,a+n+1);
    //Min Necessary:[ll,rr]
    ll=0,rr=n+1;
    while (rr>ll){
        int mid=(ll+rr)>>1;
        int necessary=0;
        if (a[mid]>=k){
            rr=mid;
            continue;
        }
        bs.reset(); // bs=0
        bs[0]=1; // bs[0]=1;
        for (int i=1;i<=n;i++)
            if (i!=mid)
                bs|=(bs<<a[i]);
        for (int i=k-1;i>=k-a[mid];i--){
            if (bs[i]){
                necessary=1;
                break;
            }
        }
        if (necessary)
            rr=mid;
        else
            ll=mid+1;
    }
    printf("%d",ll-1);
    return 0;
}