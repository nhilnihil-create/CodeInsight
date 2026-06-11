#include <algorithm>
#include <bitset>
#include <chrono>
#include <complex>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = int64_t;
struct Solution {
    void solve(std::istream& in, std::ostream& out) {
        ll n;
        in >> n;
        ll lo, hi;
        ll i = 1, sum = 1;
        while (i * (i + 1) < 2 * n) {
            i++;
            sum += i;
        }
        for (int j = 1; j <= i; j++) {
            if (sum - j != n) {
                out << j << '\n';
            }
        }
    }
};
void solve(std::istream& in, std::ostream& out) {
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    istream& in = cin;
    ostream& out = cout;
    solve(in, out);
    return 0;
}
