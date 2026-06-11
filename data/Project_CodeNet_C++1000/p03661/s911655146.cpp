#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
long long pre[200005],sum,ans=0x3f3f3f3f3f3f3f3f;
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) {cin>>a[i]; sum+=a[i];}
    for (int i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];
    for (int i=1; i<n; i++) {
        ans=min(ans,abs(2*pre[i]-sum));
    }
    cout<<ans<<'\n';
}