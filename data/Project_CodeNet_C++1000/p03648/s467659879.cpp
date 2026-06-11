#include<cstdio>

int main(){
    //printf("%lld\n",50ll*10000000000000000ll);
    long long x;
    scanf("%lld",&x);
    long long n = 50;
    long long cnt = x/n, left = x%n;
    printf("%lld\n",n);
    for(int i = 1; i <= n; i++){
        if(i<=left) printf("%lld ",cnt+n-1-(left-1)+n);
        else printf("%lld ",cnt+n-1-left);
    }
    printf("\n");
    return 0;
}
