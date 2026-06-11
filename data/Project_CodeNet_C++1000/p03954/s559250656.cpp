#include<iostream>
#include<cstdio>
using namespace std;
int n,a[200010];
bool check(int k){
    if((a[n-1]<=k&&a[n]<=k)||(a[n]<=k&&a[n+1]<=k)) return 1;
    if((a[n-1]>k&&a[n]>k)||(a[n]>k&&a[n+1]>k)) return 0;
    for(int i=1;i<n-1;i++){
        if((a[n+i]<=k&&a[n+i+1]<=k)||(a[n-i]<=k&&a[n-i-1]<=k)) return 1;
        if((a[n+i]>k&&a[n+i+1]>k)||(a[n-i]>k&&a[n-i-1]>k)) return 0;
    }
    return a[1]<=k;
}
int main(){
    cin>>n;
    for(int i=1;i<n<<1;i++) scanf("%d",a+i);
    int l=1,r=(n<<1)-1;
    int ans=0;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid;ans=mid;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;
}
