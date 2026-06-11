#include <bits/stdc++.h>
using namespace std;

int n,a[300][300];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) scanf("%d",&a[i][j]);

    long long ans=0;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++) if(i!=j) {
        int mx=2e9+1;
        for(int k=0;k<n;k++)if(i!=k && j!=k) mx=min(mx,a[i][k]+a[k][j]);
        if(mx < a[i][j]) {
            puts("-1");
            return 0;
        }else if(mx>a[i][j]) ans += a[i][j];
    }
    printf("%lld\n",ans);

    return 0;
}
