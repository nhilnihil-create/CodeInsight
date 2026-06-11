#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void){
    // Your code here!
    int N,C,K;
    int T[100000];
    int cnt = 0;
    
    scanf("%d%d%d",&N,&C,&K);
    
    for(int i = 0; i < 100000; i++){
        scanf("%d",&T[i]);
    }
    
    sort(T, T + N);
    for(int i = 0; i < N; i++){
        int c = C -1;
        int max_time = T[i] + K;
        cnt++;
        while(c > 0){
            if(T[i+1] <= max_time){
                i++;
                c--;
            }
            else{
                break;
            }
        }
    }
    
    printf("%d\n",cnt);
}
