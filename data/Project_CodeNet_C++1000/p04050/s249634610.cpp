#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+10;
int a[N],b[N*2],lis[3];
int n,m,cnt;
bool firstcheck(){
    int cnt=0;
    for (int i=1;i<=n;++i)
        cnt+=a[i]&1;
    return cnt<=2;
}
void get_b(){
    int sum;
    if (cnt==0){
        b[++b[0]]=1; sum=m-1;
        for (int i=1;i<n;++i) b[++b[0]]=a[i],sum-=a[i];
        if (sum==0) return;
        sum-=1; sum/=2;
        for (int i=1;i<=sum/2;++i) b[++b[0]]=2;
        b[++b[0]]=1;
        for (int i=sum/2+1;i<=sum;++i) b[++b[0]]=2;
    }
    else if (cnt==1){
        b[++b[0]]=1;
        for (int i=1;i<n;++i) b[++b[0]]=a[i];
        for (int i=1;i<=(a[n]-1)/2;++i) b[++b[0]]=2;
    }
    else{
        b[++b[0]]=a[1]+1;
        for (int i=2;i<n;++i) b[++b[0]]=a[i];
        for (int i=1;i<=(a[n]-1)/2;++i) b[++b[0]]=2;
    }
}

int main(){
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;++i) scanf("%d",a+i);
    if (!firstcheck()){printf("Impossible\n"); return 0;}
    cnt=0;
    for (int i=1;i<=n;++i){
        if ((a[i]&1)) 
            lis[++cnt]=i;
    }
    if (lis[1]) swap(a[n],a[lis[1]]);
    if (lis[2]) swap(a[1],a[lis[2]]);
    for (int i=1;i<=n;++i) printf("%d ",a[i]); printf("\n");

    get_b();
    printf("%d\n",b[0]);
    for (int i=1;i<=b[0];++i) printf("%d ",b[i]); printf("\n");
}