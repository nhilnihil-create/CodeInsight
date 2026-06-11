#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    std::vector<long long> v(N);
    for(int i=0; i<N; i++) scanf(" %lld", &v[i]);

    std::sort(v.begin(), v.end());
    long long sum = 0;
    int count = 1;
    for(int i=0; i<A; i++) sum += v[N-1-i];
    for(int i=N-1; i>0; i--){
        if(v[i] != v[i-1]) break;
        count++;
    }

    int maxN = 50;
    std::vector<std::vector<long long> > comb(maxN+1, std::vector<long long>(maxN+1, 1));
    for(int i=1; i<=maxN; i++){
        for(int j=1; j<i; j++) comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
    }
    
    // printf("count = %d\n", count);
    printf("%.6f\n", 1.0 * sum / A);
    if(count < A){
        int c1 = 0, c2 = 0;
        for(int i=0; i<N; i++){
            if(v[i] == v[N-A]) c1++;
        }
        for(int i=0; i<A; i++){
            if(v[N-1-i] == v[N-A]) break; c2++;
        }
        // printf("c1, c2 = %d, %d\n", c1, c2);
        std::cout << comb[c1][A-c2] << std::endl;
    }
    else{  
        long long sum_c = 0;
        int m = std::min(count, B);
        for(int i=A; i<=m; i++) sum_c += comb[count][i];
        std::cout << sum_c << std::endl;
    }
}