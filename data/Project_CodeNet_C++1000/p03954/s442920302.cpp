#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,inf=1e9;
int a[N],b[N],n;
bool cal(int md){
    for(int i=1;i<=2*n-1;i++)b[i]=a[i]>=md;
    for(int i=0;i<n-1;i++){
        if(b[n+i]==b[n+i+1])return b[n+i];
        if(b[n-i]==b[n-i-1])return b[n-i];
    }
    return b[1];
}
int main(){
    scanf("%d",&n);for(int i=1;i<=2*n-1;i++)scanf("%d",&a[i]);
    int l=1,r=2*n-1,mid,ans;
    while(l<=r){mid=l+r>>1;cal(mid)?(l=mid+1,ans=mid):r=mid-1;}
    printf("%d\n",ans);
}
