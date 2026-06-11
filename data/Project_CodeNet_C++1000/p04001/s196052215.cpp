#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <stack>
#include <tuple>

using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 100000000;
const long long LINF = 1000000000000000000;
const long long MOD = 998244353;
const double EPS = 1e-6;
using pii = std::pair<int, int>;
using ll = long long;
using pLL = std::pair<ll, ll>;
#define SORT(v) std::sort(v.begin(), v.end())
#define RSORT(v) std::sort(v.rbegin(), v.rend())
constexpr auto PI = 3.14159265358979323846264338327950L;
int main() {
    string S;
    cin >> S;
    int N = S.size();
    long long res = 0;
    for (int bit = 0; bit < (1 << (N - 1)); ++bit) {
        long long tmp = 0;
        for (int i = 0; i < N - 1; ++i) {
            tmp *= 10;
            tmp += S[i] - '0';

            if (bit & (1 << i)) res += tmp, tmp = 0;
        }
        tmp *= 10;
        tmp += S.back() - '0';

        res += tmp;
    }
    cout << res << endl;
}
