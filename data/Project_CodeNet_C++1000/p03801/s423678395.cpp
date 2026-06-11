#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int a[100005];
LL ans[100005];
pii p[100005];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        p[i] = pii(a[i], -i);
    }
    p[n+1] = pii(0, 0);
    sort(p+1, p+1+n);
    reverse(p+1, p+1+n);

    int mn = 1e9;
    for(int i=1;i<=n;i++){
        mn = min(mn, -p[i].second);
        if(a[-p[i].second] != a[-p[i+1].second]){
            int d = a[-p[i].second]-a[-p[i+1].second];
            ans[mn] += d*1ll*i;
        }
    }
    for(int i=1;i<=n;i++) printf("%lld\n", ans[i]);
}