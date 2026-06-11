#include <stdio.h>
 
int main(void){
    // Your code here!
    int N,flag;
    int A[100000],cnt[100000];
    int ans=1;
    
    scanf("%d",&N);
    
    if(N % 2 == 0){
        flag = 0;
    }
    else{
        flag = 1;
    }
    
    for(int i = 0; i < N; i++){
        int num;
        if(flag == 0 && i % 2 == 1){
            cnt[i] = 2;
        }
        else if(flag == 1 && i % 2 == 0){
            if(i == 0){
                cnt[i] = 1;
            }
            else{
                cnt[i] = 2;
            }
        }
        else{
            cnt[i] = -1;
        }
    }
    
    for(int i = 0; i < N; i++){
        scanf("%d",&A[i]);
        if(cnt[A[i]] > 0){
            cnt[A[i]]--;
        }
        else{
            printf("0\n");
            return 0;
        }
    }
    
    for(int i = 0;i<N/2;i++){
        ans = (ans * 2) % 1000000007;
    }
    
    
    printf("%d\n",ans);
}