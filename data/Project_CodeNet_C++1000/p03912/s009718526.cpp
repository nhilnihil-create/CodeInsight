#include <iostream>
#include <vector>
 
#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)

constexpr int MAX_SIZE = 1e5 + 1;
std::vector<int> A, B;
std::vector<int> Count(MAX_SIZE, 0);

int main(void){
    int n, m; scanf("%d%d", &n, &m);
    A.resize(m, 0);
    REP(i, n) {
        int a; scanf("%d", &a);
        A[a % m]++;
        Count[a]++;
    }
    B.resize(m, 0);
    REP(x, MAX_SIZE) B[x % m] += (Count[x] >> 1);
    // x個あって, aペア作れる <~> y個あって, bペア作れる

    int cnt = 0;
    REP(i, m){
        int j = (m - i) % m;
        if(j < i) break;
        if(i == j) {cnt += A[i] / 2; continue;}
        int p = std::min(A[i], A[j]);
        cnt += p; A[i] -= p; A[j] -= p;
        int q1 = std::min(A[i] / 2, B[i]);
        int q2 = std::min(A[j] / 2, B[j]);
        cnt += q1 + q2;
    }
    printf("%d\n", cnt);
    

    return 0;
}
