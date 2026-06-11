#include <iostream>
#include <vector>

int main()
{
    const long long infty = 1e+18;

    int N;
    long long x;
    scanf("%d %lld", &N, &x);
    std::vector<long long> a(N);
    for(int i=0; i<N; i++) scanf(" %lld", &a[i]);

    long long min_t = infty;
    std::vector<long long> m(N, infty);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(a[(j+i)%N] < m[j]) m[j] = a[(j+i)%N];
        }

        long long tmp = i * x;
        for(int j=0; j<N; j++) tmp += m[j];
        if(tmp < min_t) min_t = tmp;
    }

    std::cout << min_t << std::endl;
}