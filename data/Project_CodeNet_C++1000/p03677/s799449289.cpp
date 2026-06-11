#include <iostream>
#include <limits>
#include <cfenv>
#include <cmath>
#include <algorithm>
#include <array>
#include <bitset>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <tuple>
#include <queue>
#include <vector>
#include <cmath>
#include <random>
#include <math.h>
#include <list>
#include <random>
#include <functional>


#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define rREP(i, n) for(int (i) = (n) - 1; (i) >= 0; --(i))
#define ALL(TheArray) TheArray.begin(), TheArray.end()

using lli = long long int;
using pii = std::pair<int, int>;

template <class T> inline bool chmax(T& a, T b){
    if(a < b){a = b; return true;}
    return false;
}
template <class T> inline bool chmin(T& a, T b){
    if(a > b){a = b; return true;}
    return false;
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

constexpr int N = 1e5;
std::array<int, N> A;
std::array<lli, N+1> Count, Wait;
std::array<lli, N+1> S;

int main(void){
    int n, m; scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", &A[i]), A[i]--;
    // a -> b に遷移する場合 | お気に入り設定でどれだけ変化するか考えよう
    // a < b の場合 : a < j ≤ b なる全ての j に関してコストが j - a - 1 だけ減少する
    // a > b の場合 : 1, a < j < m なるすべての j に関してコストが j - a - 1だけ減少する
    //               2, a < j + m ≤ b + m なる全ての j に関して ( : 0 ≤ j < m)
    //                     コストが j + m - a - 1 だけ減少する
    lli T = 0;
    for(int i = 1; i < n; ++i){
        if(A[i-1] < A[i]){
            int l = A[i-1] + 2;
            int r = A[i] + 1;
            Count[l]++; Count[r]--;
            Wait[r] += r - l;
            T += A[i] - A[i-1];
        }
        else{
            int l = A[i-1] + 2;
            int r = m;
            Count[l]++; Count[r]--;
            Wait[r] += r - l;
            l = 0; r = A[i] + 1;
            Count[l]++; Count[r]--;
            Wait[r] += r - l;
            S[l] += m - A[i-1] - 2;
            S[r] -= m - A[i-1] - 2;
            T += (A[i] + m - A[i-1]);
        }
    }

    REP(i, m) Count[i+1] += Count[i], S[i+1] += S[i];

    Count[0] -= Wait[0]; S[0] += Count[0];
    REP(i, m) Count[i+1] += Count[i] - Wait[i+1], S[i+1] += Count[i+1];
    lli mx = 0;
    REP(i, m) if(mx < S[i]) mx = S[i];
    printf("%lld\n", T - mx);
    
    return 0;
}
