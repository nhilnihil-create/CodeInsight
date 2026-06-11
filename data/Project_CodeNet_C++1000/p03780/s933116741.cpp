#include <cstdio>
#include <algorithm>
#include <bitset>
#define MAXN 5005
#define MAXBS 5005
using namespace std;
bitset<MAXBS> bs;
int a[MAXN];
int main(void){
    int n,k;
    int ll,rr;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    sort(a,a+n);
    n=lower_bound(a,a+n,k)-a;
    //(ll,rr] 
    ll=-1,rr=n;
    while (rr-ll>1){
        int mid=(ll+rr+1)>>1;
        int necessary=0;
        bs.reset(); // bs=0
        bs.set(0); // bs[0]=1;
        for (int i=0;i<n;i++)
            if (i!=mid)
                bs|=(bs<<a[i]);
        bs>>=(k-a[mid]);
        for (int i=0;i<a[mid];i++){
            if (bs.test(i)){
                necessary=1;
                break;
            }
        }
        if (necessary)
            rr=mid;
        else
            ll=mid;
    }
    printf("%d\n",ll+1);
    return 0;
}
