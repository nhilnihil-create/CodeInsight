#include<cstdio>
#include<algorithm>
long long a[200000];
int main(){
    int n;
    scanf("%d%lld",&n,&a[0]);
    for(int i=1;i<n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    long long bmin=1e15;
    for(int i=0;i<n-1;i++){
        bmin=std::min(bmin,std::abs(2*a[i]-a[n-1]));
    }
    printf("%lld",bmin);
    return 0;
}