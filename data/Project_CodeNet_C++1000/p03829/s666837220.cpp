#include <stdio.h>

int main(void) {

    long long N,A,B;
    int i;
    long long cnt = 0;

    scanf("%lld %lld %lld", &N, &A, &B);
    long long X[N];
    long long dis = 0;
    for(i=0;i<N;i++){
        scanf("%lld",&X[i]);
    }

    for(i = 1;i < N;i++){
        dis = X[i] - X[i-1];
        if(B > dis * A){
            cnt += dis * A;
        }
        else{
            cnt += B;
        }

        //printf("%lld %lld %lld\n", dis*A, B, cnt);
    }

    printf("%lld\n", cnt);

    return 0;
}