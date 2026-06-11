#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;

const long long INF = 1LL<<10;

void solve(long long n, vector< vector<long long> > A) {
    bool is_need_edge = true;
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            is_need_edge = true;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) {
                    continue;
                }
                if (A[i][j] > A[i][k] + A[j][k]) {
                    std::cout << -1 << std::endl;
                    return;
                }
                if (A[i][j] == A[i][k] + A[j][k]) {
                    is_need_edge = false;
                }
            }
            if (is_need_edge) {
                ret += A[i][j];
            }
        }
    }
    std::cout << ret << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    long long n;

    gettimeofday(&start,NULL);

    std::cin >> n;
    vector< vector<long long> > A(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> A[i][j];
        }
    }
    solve(n, A);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
