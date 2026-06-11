#include<cstdio>
#include<queue>
using namespace std;
int main() {
    int n,cur=2,x;
    long long ans;
    scanf("%d",&n);
    scanf("%lld",&ans);
    ans--;
    for(int i=1;i<n;i++) {
        scanf("%d",&x);
        if(x==cur) cur++;
        else ans+=x/cur-(x%cur==0);
    }
    printf("%lld\n",ans);
    return 0;
}