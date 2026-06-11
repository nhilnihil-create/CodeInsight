#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

constexpr static ll MOD = 1000000007ll;
constexpr static int INF = 1 << 28; // for x <= 10^9
constexpr static ll INFL = 1ll << 60; // for x <= 10^19

int main() {
    int n;
    cin >> n;

    int maxA = -1, maxB = -1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (maxA < a) {
            maxA = a;
            maxB = b;
        }
    }

    cout << (maxA + maxB) << endl;
}
