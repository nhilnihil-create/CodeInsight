#include <stdio.h>

int main(void){
    int N,T,t[200000];
    long long time_ans = 0;
    
    scanf("%d%d",&N,&T);
    
    for(int i = 0; i < N; i++){
        scanf("%d",&t[i]);
    }
    
    time_ans += T;
    for(int i = 1; i < N; i++){
        if(t[i] - t[i-1] > T){
            time_ans += T;
        }
        else{
            time_ans += t[i] - t[i-1];
        }
    }
    
    printf("%lld\n",time_ans);
}