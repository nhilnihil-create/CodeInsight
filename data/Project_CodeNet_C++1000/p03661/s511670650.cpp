#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n;
lli arr[200001];
lli _abs(lli a){return a<0 ? -a : a;}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",arr+i),arr[i]+=arr[i-1];
    lli mx=1e18;
    for(int i=1;i<n;i++) {
        mx = min(mx, _abs(2*arr[i]-arr[n]));
    }
    printf("%lld\n",mx);
    
    return 0;
}
