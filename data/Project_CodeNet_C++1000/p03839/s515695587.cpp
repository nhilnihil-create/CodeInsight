#include<bits/stdc++.h>

int main(){
    int N,K;
    std::cin>>N>>K;
    std::vector<long long> A(N),S(N+1),black(N+1);
    for(int i=0;i<N;++i){
        std::cin>>A[i];
        S[i+1]=S[i]+A[i];
        black[i+1]=black[i]+((A[i]>0)?A[i]:0);
    }
    long long ans=-1e18,tmp;
    for(int i=0;i<=N-K;++i){
        tmp = (S[i+K]-S[i]>0)?(S[i+K]-S[i]):0;
        tmp += black[i]+black[N]-black[i+K];
        ans = std::max(ans,tmp);
    }
    std::cout<<ans<<std::endl;
}