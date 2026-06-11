#include <iostream>
#include <vector>
long long INF = 1e18;
long long N, K;
std::vector<long long> a;
int main(){
    std::cin >> N >> K;
    a.resize(N);
    for(int i = 0; i < N; i++) std::cin >> a[i];
    long long ans = INF;
    for(int bit = 0; bit < (1 << N - 1); bit++){
        std::vector<int> sele(N - 1, 0);
        int count = 0;
        for(int i = 0; i < N - 1; i++){
            if(bit & (1 << i)) {
                count++;
                sele[i] = 1;
            }
        }
        if(count < K - 1) continue;
        long long res = 0;
        long long M = a[0];
        for(int i = 0; i < N - 1; i++){
            if(sele[i] == 1 && M >= a[i + 1]){
                res += M + 1 - a[i + 1];
                M++;
            }
            M = std::max(M, a[i + 1]);
        }
        ans = std::min(ans, res);
    } 
    std::cout << ans << std::endl;
}