#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int64_t test(int N, int A, int X[]);
int main(void) {
    char *p;
    char str[256];

    int *X;
    int N=1,A=1;
    int i,cnt=0;

    p = fgets(str, 256, stdin);
    for(i=0;i<256;i++){
        if(str[i] == ' ') {
            str[i] = '\0';
            N = atoi(p);
            A = atoi(&str[i+1]);
            break;
        }
    }
    
    X = (int*)malloc(sizeof(int) * N);
    p = fgets(str, 256, stdin);
    for(i=0;i<256;i++){
        if(str[i] == ' '){
            str[i] = '\0';
            X[cnt++] = atoi(p);
            p = &str[i+1];
        }else if(str[i] < '0' || str[i] > '9') {
            break;
        }
    }
    X[cnt] = atoi(p);
    
    printf("%ld\n", test(N,A,X));
    free(X);

    return 0;
}

int64_t test(int N, int A, int X[]) {
    int j,t;
    int64_t **dp;
    int64_t sum = 0;
    int tmax;
    int Xm = A;


    int *Y = (int*)malloc(sizeof(int) * N);
    for(j=0;j<N;j++){
        Y[j] = X[j] - A;
        if(Xm < X[j]) Xm = X[j];
    }
    tmax = 2 * N * Xm;
    dp = (int64_t**)calloc(1,sizeof(int64_t*) * (N+1) + (sizeof(int64_t) * ((2 * (N+1)*Xm*(N+1)) + 1)));
    for(j=0;j<=N;j++){
        dp[j] = (int64_t*)(((char*)dp) + (sizeof(int64_t*)*(N+1)) + (sizeof(int64_t) * j *(N+1)* 2 * Xm));
    }

    dp[0][N * Xm] = 1;
    for(j=1;j<=N;j++){
        for(t=0;t<=tmax;t++){
            if((t-Y[j-1] < 0) || ((t-Y[j-1]) > tmax)){
                dp[j][t] = dp[j-1][t];
            } else if((0 <= (t-Y[j-1])) && ((t-Y[j-1]) <= tmax)){
                dp[j][t] = dp[j-1][t] + dp[j-1][t-Y[j-1]];
            }
        }
    }
    
    sum = dp[N][N*Xm] - 1;
    free(Y);
    free(dp);
    return sum;
}
