#include <stdio.h>

int main(void){
    // Your code here!
    int N,T[1000],A[1000];
    long long takahashi=0,aoki=0,tmp_t=0,tmp_a=0;
    
    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
        scanf("%d%d",&T[i],&A[i]);
    }
    
    for(int i=0;i<N;i++){
        tmp_t = T[i];
        tmp_a = A[i];
        if(tmp_t < takahashi || tmp_a < aoki){
            long long max = 0;
            long long Tmax = (takahashi+tmp_t-1)/tmp_t;
            long long Amax = (aoki+tmp_a-1)/tmp_a;
            if(Tmax > Amax){
                max = Tmax;
            }
            else{
                max = Amax;
            }
            
            tmp_t *= max;
            tmp_a *= max;
        }
        
        takahashi = tmp_t;
        aoki = tmp_a;
        //printf("takahashi_%lld,aoki_%lld\n",takahashi,aoki);
    }
    
    printf("%lld\n",takahashi+aoki);
}
