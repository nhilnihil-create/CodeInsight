#include <bits/stdc++.h>
using namespace std;
using LL = long long; using PII = pair<LL, LL>; using VI = vector<LL>; using VVI = vector<VI>;
using VB = vector<bool>; using VS = vector<string>; using VP = vector<PII>;
#define VV(T)        vector<vector<T>>
#define PB           push_back
#define MP           make_pair
#define SZ(a)        LL((a).size())
#define EACH(x, c)   for (auto x : (c))
#define ALL(c)       (c).begin(), (c).end()
#define REVERSE(c)   reverse(ALL(c))
#define SORT(c)      stable_sort(ALL(c))
#define RSORT(c)     stable_sort((c).rbegin(), (c).rend())
#define FOR(i, a, b) for (LL i = (a); i < (b); ++i)
#define REP(i, n)    FOR(i, 0, n)
#define $(x)         {cout << #x << " = " << (x) << endl;}


void solve(long long N, long long M, std::vector<std::vector<long long>> A){
    unordered_set<LL> masked_sports;
    VI pos(N, 0);
    LL min_max_count = N;
    while (SZ(masked_sports) < M) {
        unordered_map<LL, LL> counts;
        REP(i, N) {
            while (masked_sports.count(A[i][pos[i]]) > 0) {
                pos[i]++;
            }
            counts[A[i][pos[i]]]++;
        }
        LL max_count = 0, max_count_sport;
        EACH(c, counts) {
            if (max_count < c.second) {
                max_count_sport = c.first;
                max_count = c.second;
            }
        }
        min_max_count = min(min_max_count, max_count);
        masked_sports.insert(max_count_sport);
    }
    cout << min_max_count << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<std::vector<long long>> A(N, std::vector<long long>(M));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf("%lld",&A[i][j]);
        }
    }
    solve(N, M, std::move(A));
    return 0;
}
