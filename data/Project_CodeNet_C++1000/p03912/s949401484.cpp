#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

constexpr int MOD = 1000000007;


constexpr int LIM = 100000;
int N, M;
int v[100010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    fill(v, v+100010, 0);
    for (int j = 0; j < N; ++j) {
        int w;
        cin >> w;
        v[w] ++;
    }

    int ret = 0;

    for (int j = 0; j <= M/2; ++j) {
        int rj = (M - j) % M;

        int countj = 0;
        for (int k = j; k <= LIM; k += M) {
            countj += v[k];
        }

        int countrj = 0;
        for (int k = rj; k <= LIM; k += M) {
            countrj += v[k];
        }

        int del = min(countj, countrj);
        ret += del / (j == rj ? 2 : 1);
        int tmp = j == rj ? del / 2 * 2 : del;
        for (int k = j; k <= LIM; k += M) {
            if (v[k] % 2 == 1) {
                --v[k]; --tmp;
            }
        }
        for (int k = j; k <= LIM && tmp > 0; k += M) {
            int dec = min(v[k], tmp);
            tmp -= dec; v[k] -= dec;
        }

        if (rj != j) {
            tmp = del;
            for (int k = rj; k <= LIM; k += M) {
                if (v[k] % 2 == 1) {
                    --v[k]; --tmp;
                }
            }
            for (int k = rj; k <= LIM && tmp > 0; k += M) {
                int dec = min(v[k], tmp);
                tmp -= dec; v[k] -= dec;
            }
        }
    }

    for (int j = 0; j <= LIM; ++j) {
        ret += v[j] / 2;
    }

    cout << ret << endl;
    return 0;
}
