#include <iostream>
#include <vector>

int main()
{
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for(int i=0; i<N; i++) scanf(" %lld", &A[i]);

    long long sum = 0;
    for(int i=0; i<N; i++) sum += A[i];
    if(sum % (N*(N+1)/2) != 0){
        printf("NO\n"); return 0;
    }
    sum /= N*(N+1)/2;

    bool flag = true;
    for(int i=0; i<N-1; i++){
        if((A[i] + sum - A[i+1]) % N != 0) flag = false;
        if(A[i] + sum - A[i+1] < 0) flag = false;
    }
    if((A[N-1] + sum - A[0]) % N != 0) flag = false;
    if(A[N-1] + sum - A[0] < 0) flag = false;

    if(flag == true) printf("YES\n");
    else printf("NO\n");
}