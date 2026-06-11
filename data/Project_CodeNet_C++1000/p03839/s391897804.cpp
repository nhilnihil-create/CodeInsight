#include <iostream>
#include <vector>

int main()
{
    // input
    int N, K;
    std::cin >> N >> K;
    std::vector<long long> a(N);
    for(int i=0; i<N; i++) scanf(" %lld", &a[i]);

    std::vector<long long> sum_l(N), sum_r(N);
    sum_l[0] = a[0] > 0 ? a[0] : 0;
    sum_r[N-1] = a[N-1] > 0 ? a[N-1] : 0;
    for(int i=1; i<N; i++){
        sum_l[i] = sum_l[i-1];
        sum_r[N-1-i] = sum_r[N-i];
        if(a[i] > 0) sum_l[i] += a[i];
        if(a[N-1-i] > 0) sum_r[N-1-i] += a[N-1-i];
    }
    std::vector<long long> sum_K(N, 0);
    for(int i=0; i<K; i++) sum_K[0] += a[i];
    for(int i=1; i+K-1<N; i++) sum_K[i] = sum_K[i-1] - a[i-1] + a[i+K-1];

    long long max = 0;
    for(int i=0; i+K+1<N; i++){
        long long tmp = sum_l[i] + sum_r[i+K+1];
        if(sum_K[i+1] > 0) tmp += sum_K[i+1];
        if(max < tmp) max = tmp;
    }
    if(K<N && max < sum_r[K]) max = sum_r[K];
    if(K<N && max < sum_K[0] + sum_r[K]) max = sum_K[0] + sum_r[K];
    if(K<N && max < sum_l[N-1-K]) max = sum_l[N-1-K];
    if(K<N && max < sum_l[N-1-K] + sum_K[N-K]) max = sum_l[N-1-K] + sum_K[N-K];
    if(K==N && max < sum_K[0]) max = sum_K[0]; 

    // output
    std::cout << max << std::endl;
}