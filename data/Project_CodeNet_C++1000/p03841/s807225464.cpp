#include<bits/stdc++.h>
#define N 505
using namespace std;
int n,a[N];
int ans[N*N],arr[N];
bool cmp(int ta,int tb){
    return a[ta]<a[tb];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),ans[a[i]]=i,arr[i]=i;
    sort(arr+1,arr+n+1,cmp);
    for(int i=1;i<=n;i++){
        int v=arr[i],cnt=v-1;
        for(int j=1;j<a[v];j++)
            if(ans[j]==0&&cnt!=0) ans[j]=v,cnt--;
        if(cnt!=0) return puts("No"),0;
    }
    for(int i=n;i>=1;i--){
        int v=arr[i],cnt=n-v;
        for(int j=n*n;j>a[v];j--)
            if(ans[j]==0&&cnt!=0) ans[j]=v,cnt--;
        if(cnt!=0) return puts("No"),0;
    }
    puts("Yes");
    for(int i=1;i<=n*n;i++) printf("%d ",ans[i]);
    return 0;
}