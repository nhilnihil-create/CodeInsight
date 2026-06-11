#include <bits/stdc++.h>
using namespace std;
int a[200100],n;
bool check(int x){
    for(int i=0;i<=n-1;i++){
        if((a[n-i]<x&&a[n-i-1]<x)||(a[n+i]<x&&a[n+i+1]<x))
            return false;
        if((a[n-i]>=x&&a[n-i-1]>=x)||(a[n+i]>=x&&a[n+i+1]>=x))
            return true;
    }
    return a[2*n-1]>=x;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++){
        scanf("%d",&a[i]);
    }
    int l=1,r=2*n-1,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))
            l=mid+1,ans=mid;
        else
            r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}