#include<bits/stdc++.h>
using namespace std;

long long int N, M, A[101010], B[101010], C[101010], a, b;

int main(){
    scanf("%lld%lld", &N, &M);
    for(int i = 0; i < N; ++i){
        scanf("%lld", A + i);
        --A[i];
    }
    for(int i = 0; i < N - 1; ++i){
        ++B[A[i] + 1];
        --B[A[i + 1]];
        if(A[i] > A[i + 1]){
            ++B[0];
            a += 1 + A[i + 1];
        }else{
            a += A[i + 1] - A[i];
        }
        C[A[i + 1]] += (M - A[i] + A[i + 1]) % M - 1;
    }
    partial_sum(B, B + M, B);
    b = a;
    for(int i = 0; i < M - 1; ++i){
        b += C[i] - B[i];
        a = min(a, b);
    }
    cout << a << endl;
    return 0;
}
