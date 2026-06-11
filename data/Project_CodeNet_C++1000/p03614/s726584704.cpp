#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int main() {
    scanf("%d",&n);
    for (int i=1,x;i<=n;++i) {
        scanf("%d",&x),a[i]=(i==x);
    }
    int ans=0;
    for (int i=1;i<=n;++i) {
        if (a[i]) a[i]=a[i+1]=0,++ans;
    }
    printf("%d\n",ans);
}
