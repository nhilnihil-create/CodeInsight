#include <stdio.h>

int main(void){
    // Your code here!
    int N;
    int num[1001]={};
    long long ans = 1;
    
    scanf("%d",&N);
    
    for(int i = 2;i<=N;i++){
        int n = i;
        int j = 2;
        while(n != 1){
            while(n % j == 0){
                num[j]++;
                n /= j;
            }
            j++;
        }
    }
    
    for(int i = 2;i<=N;i++){
        if(num[i] > 0){
            //printf("i-%d:%d\n",i,num[i]);
            ans = (ans * (num[i]+1)) % 1000000007;
            
        }
    }
    
    printf("%lld\n",ans);
}
