#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    ll a, b, x;
    cin >> a >> b >> x;
    ll aa = (a+x-1)/x, bb = (b/x);
    cout << max(0LL, bb-aa+1) << endl;
}