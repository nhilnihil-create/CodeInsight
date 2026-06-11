#include<bits/stdc++.h>
using namespace std;
int f[5050],a[5050],n,k,sum=0;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]=min(a[i],k),sum+=a[i];
    sort(a+1,a+n+2),f[0]=1;
    for(int i=n+1;i;--i){
        bool check=true;
        for(int j=k-1;j>=k-sum&&j>=0;--j)if(f[j]){check=false;break;}
        if(check){printf("%d",i-1);return 0;}
        for(int j=k;j>=a[i];--j)f[j]|=f[j-a[i]];
        sum-=a[i];
    }
    return 0;
}
