#include <bits/stdc++.h>
using namespace std;

const long long INF = 3LL << 60;

long long memo[100005][3];

long long A[100005];
char op[100005];

int N;

long long dp(int i, int j){
    if(i == N){
        return 0;
    }else if(memo[i][j] != -INF){
        return memo[i][j];
    }else if(op[i] == '+'){
        if(j == 0){
            return memo[i][j] = A[i] + dp(i+1, 0);
        }else if(j == 1){
            return memo[i][j] = -A[i] + max(dp(i+1, 1), dp(i+1, 0));
        }else if(j == 2){
            return memo[i][j] = A[i] + max(dp(i+1, 2), dp(i+1, 1));
        }
    }else if(op[i] == '-'){
        if(j == 0){
            return memo[i][j] = max(-A[i] + dp(i+1, 1), -A[i]+dp(i+1, 0));
        }else if(j == 1){
            return memo[i][j] = max(max(A[i] + dp(i+1, 1), A[i]+dp(i+1, 2)), A[i]+dp(i+1, 0));
        }else if(j == 2){
            return memo[i][j] = max(-A[i] + dp(i+1, 1), -A[i]+dp(i+1, 2));
        }
    }
}

int main(){
    scanf("%d", &N);

    scanf("%d", &A[0]);
    op[0] = '+';
    for(int i = 1; i < N; i ++){
        scanf(" %c %d", &op[i], &A[i]);
    }

    for(int i = 0; i <= N; i ++){
        for(int j = 0; j < 3; j ++){
            memo[i][j] = -INF;
        }
    }

    /*for(int i = 0; i <= N; i ++){
        for(int j = 0; j < 3; j ++){
            printf("memo[%d][%d] = %lld\n", i, j, dp(i, j));
        }
    }*/

    printf("%lld", dp(0, 0));
    return 0;
}
