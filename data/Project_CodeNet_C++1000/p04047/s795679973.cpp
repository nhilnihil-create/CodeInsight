#include <bits/stdc++.h>
using namespace std;
int n,a[1000],ans;
int main() {
    scanf("%d",&n); n<<=1;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i+=2) ans+=a[i];
    printf("%d",ans);
}