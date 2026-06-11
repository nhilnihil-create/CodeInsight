#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=200005;
int n,a[max_n];
int main(){
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        sum+=a[i];
    }
    ll x=0;
    ll ans=1e18;
    for(int i=1;i<n;i++){
        x+=a[i];
        ans=min(ans,abs(sum-2*x));
    }
    printf("%lld\n",ans);
    return 0;
}