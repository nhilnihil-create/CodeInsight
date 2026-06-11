#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
int n,t;
LL a[maxn],b[maxn];
int main() {
    while (~scanf("%d%d",&n,&t)) {
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for (int i=n;i>=1;i--) b[i]=max(b[i+1],a[i]);
        LL mx=0,cnt=0;
        for (int i=1;i<n;i++) {
            if (mx<b[i+1]-a[i]) {
                mx=b[i+1]-a[i];
                cnt=1;
            } else if (mx==b[i+1]-a[i]) cnt++;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
