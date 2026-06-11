#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)

using lli = long long int;
using pii = std::pair<int, int>;

template <class T> inline bool chmin(T& a, T b){
    if(a > b){a = b; return true;}
    return false;
}

constexpr int inf = 2e9;
std::vector<lli> S;
std::vector<pii> A;


int main(void){
    int n; scanf("%d", &n);
    A.resize(n+1); S.resize(n);
    REP(i, n){
        scanf("%d", &A[i].first);
        A[i].second = i;
    }
    A[n] = {0, 0};
    std::sort(A.begin(), A.end(), std::greater<pii>());

    int addr = n-1; int prev = inf;
    for(int i = 0; i <= n; ++i){
        lli K = i; K *= (prev - A[i].first);
        S[addr] += K;
        prev = A[i].first;
        chmin(addr, A[i].second);
    }
    

    // 解の出力
    REP(i, n) printf("%lld\n", S[i]);


    return 0;
}