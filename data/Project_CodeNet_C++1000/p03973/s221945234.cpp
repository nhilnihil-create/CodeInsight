#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(long long N, std::vector<long long> A){
    ll ans = 0;
    ll uku = 2;
    ans += A[0] - 1;
    for(int i = 1;i < N;i++){
        //cout<<A[i]<<" "<<uku<<endl;
        ans += (A[i] - 1) / uku;
        if(A[i] == uku)uku++;
        //cout<<ans<<endl;
    }
    /*
    for(int i = 0;i < N;i++){
        cout<<A[i]<<" ";
    }
    
    cout<<endl;
    */
    cout<<ans<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
