#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000005;

int s[N],top,a[N],l[N],r[N],n,ans;

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        while(top && a[i]<a[s[top]]) r[s[top]]=i, --top;
        s[++top]=i;
    }
    while(top) r[s[top]]=n+1, --top;
    for(int i=n;i>=1;--i) {
        while(top && a[i]<a[s[top]]) l[s[top]]=i, --top;
        s[++top]=i;
    }
    while(top) l[s[top]]=0, --top;
    for(int i=1;i<=n;i++) {
        ans += a[i] * (r[i]-i) * (i-l[i]);
    }
    cout<<ans;
}
