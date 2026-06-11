#include <stdio.h>

int main(void){
    // Your code here!
    int N;
    int a[100000];
    long long sum = 0;
    long long cnt[2] = {};
    
    scanf("%d",&N);
    
    for(int i = 0; i < N; i++){
        scanf("%d",&a[i]);
    }
    
    for(int j = 0; j < 2; j++){
        int flag = j; //even or odd integers
        sum = 0;
        for(int i = 0; i < N; i++){
            sum += a[i];
            if(i % 2 == j){
                if(sum <= 0){
                    cnt[j] += -sum + 1;
                    sum = 1;
                }
            }
            else{
                if(sum >= 0){
                    cnt[j] += sum + 1;
                    sum = -1;
                }
            }
        }
    }
    
    if(cnt[0] > cnt[1]){
        printf("%lld\n",cnt[1]);
    }
    else{
        printf("%lld\n",cnt[0]);
    }
}
