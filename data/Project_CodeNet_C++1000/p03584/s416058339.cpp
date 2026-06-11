#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include <utility>
#include <bitset>
#define sign(a) ((a>0)-(a<0))
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define LL long long
#define INF (LL)(1LL<<60)
#define all(a) a.begin(), a.end()
#define gr greater<LL>()
#define b32 bitset<32>
#define ui32 uint32_t

using namespace std;

void solve(long long N, long long K, std::vector<long long> A, std::vector<long long> B){
    ui32 tmp=0;
    bitset<32> kb(K);
    vector<ui32> masks = {~((ui32)K)};
    rep(i, 31){
        if(kb[i]==1){
            ui32 mask=K;
            mask |= tmp;
            mask = ~mask;
            mask |= (1<<i);
            masks.emplace_back(mask);
            //cout << bitset<32>(mask) << endl;
        }
        tmp |= (1<<i);
    }
    LL ans=0;
    for(auto mask:masks){
        LL total=0;
        rep(j, N)if((mask&A[j]) == 0)total+=B[j];
        ans = max(ans, total);
    }
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> A(N);
    std::vector<long long> B(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
    }
    solve(N, K, std::move(A), std::move(B));
    return 0;
}
