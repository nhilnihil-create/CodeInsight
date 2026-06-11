#include <bits/stdc++.h>
using namespace std;

int n,a[205];

int main() {
    cin>>n;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    sort(a+1,a+2*n+1);
    int ans =0 ;
    for(int i=1;i<=n;i++) ans+=min(a[i*2-1],a[i*2]);
    cout<<ans<<endl;
}