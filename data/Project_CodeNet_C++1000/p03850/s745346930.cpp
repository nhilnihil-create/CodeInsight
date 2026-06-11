
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

int n;
ll a[100010];
char op[100010];
char buf[8];
ll l=0,r=0,ans=-2e11;

int main() {
    scanf("%d",&n);
    scanf("%lld",&a[0]);
    l=a[0];
    for (int i=1;i<n;i++) {
        scanf("%s",buf);
        scanf("%lld",a+i);
        op[i]=buf[0];
        r+=a[i];
    }
    int idx=1;
    while (idx<n&&op[idx]=='+') {
        l+=a[idx];
        r-=a[idx];
        idx++;
    }
    ll tmp=0;
    while (idx<n) {
        l+=2*tmp;
        l-=a[idx];
        r-=a[idx];
        idx++;
        tmp=0;
        while (idx<n&&op[idx]=='+') {
            tmp+=a[idx];
            l-=a[idx];
            r-=a[idx];
            idx++;
        }
        ans=max(ans,l+r);
    }
    ans=max(ans,l+r);
    printf("%lld\n",ans);
}