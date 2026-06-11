#include<bits/stdc++.h>

int main(){
    int N,K;
    std::cin>>N>>K;
    std::vector<long long> a(N);
    for(int i=0;i<N;++i) std::cin>>a[i];
    long long ans=1e18;
    for(int bit=0;bit<(1<<N);++bit){
        if(__builtin_popcount(bit)<K) continue;
        long long tmp=0,height=0;
        for(int i=0;i<N;++i){
            if(bit>>i&1){
                if(a[i]<=height){
                    height++;
                    tmp+=height-a[i];
                }
                else height=a[i];
            }
            else height=std::max(height,a[i]);
        }
        ans=std::min(ans,tmp);
    }
    std::cout<<ans<<std::endl;
}