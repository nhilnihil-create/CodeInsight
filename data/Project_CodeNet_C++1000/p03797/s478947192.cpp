#include <stdio.h>

int main(void){
    long long N,M;
    long long ans;
    
    scanf("%lld%lld",&N,&M);
    
    if(N < M/2){
        ans = N;
        M -= 2*N;
        ans += M/4;
    }
    else{
        ans = M/2;
    }
    
    printf("%lld\n",ans);
    
    return 0;
}