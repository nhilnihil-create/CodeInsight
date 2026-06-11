#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <stack>
#include <limits>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <numeric>
//#include <tuple>

constexpr long long mod = static_cast<long long>(1e9 + 7);

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<long long>> A(N, std::vector<long long>(N, 0));
    for(auto& a: A) {
        for(auto& val: a) {
            std::cin >> val;
        }
    }

    auto B = A;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
                B[i][j] = std::min(B[i][j], B[i][k] + B[k][j]);
            }
        }
    }

    bool isExist = true;
    for(int i = 0;i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(B[i][j] < A[i][j]) {
                isExist = false;
                break;
            }
        }
    }

    if(!isExist) {
        std::cout << -1 << std::endl;
    } else {
        long long ans = 0;
        for(int u = 0; u < N; ++u) {
            for(int v = 0; v < N; ++v) {
                bool isAdd = true;
                for(int w = 0; w < N; ++w) {
                    if(w != u && w != v) {
                        if(A[u][v] == B[u][w] + B[w][v]) {
                            isAdd = false;
                            break;
                        }
                    }
                }
                if(isAdd) ans += A[u][v];
            }
        }
        std::cout << ans / 2 << std::endl;
    }

    return 0;
}
