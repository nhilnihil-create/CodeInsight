#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N;
    cin >> N;
    vector<unsigned long> A(N);
    for(auto& i : A)cin >> i;
    const auto S = accumulate(A.begin(), A.end(), 0UL);
    if(S % (N * (N + 1) / 2))return 0 & puts("NO");
    const auto K = S * 2 / N / (N + 1);
    A.push_back(A[0]);
    unsigned long cnt{0};
    for(unsigned long i{0}; i < N; ++i){
        if(K + A[i] < A[i + 1] || (K + A[i] - A[i + 1]) % N)return 0 & puts("NO");
        cnt += (K + A[i] - A[i + 1]) / N;
    }
    if(cnt != K)return 0 & puts("NO");
    puts("YES");
    return 0;
}