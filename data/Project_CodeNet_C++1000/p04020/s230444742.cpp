#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100010];
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        ans+=a[i]/2;
        a[i]%=2;
        if(i<n&&a[i]&&a[i+1]){ans++;a[i]--;a[i+1]--;}
    }
    printf("%lld\n",ans);
    return 0;
}