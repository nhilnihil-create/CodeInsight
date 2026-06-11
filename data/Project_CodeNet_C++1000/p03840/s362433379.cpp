/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>
#include <cstring>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <stack>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const double PI = 3.141592653589793238462643383279;
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */
signed main() {
    int aI, aO, aT, aJ, aL, aS, aZ;
    cin >> aI >> aO >> aT >> aJ >> aL >> aS >> aZ;

    int ret = 0;
    ret += aO;

    ret += (aI / 2) * 2;
    ret += (aJ / 2) * 2;
    ret += (aL / 2) * 2;

    int odd_cnt = 0;
    if (aI % 2 == 1) odd_cnt++;
    if (aJ % 2 == 1) odd_cnt++;
    if (aL % 2 == 1) odd_cnt++;

    if (odd_cnt == 3) {
        ret += 3;
    } else if (aI > 0 && aJ > 0 && aL > 0 && odd_cnt == 2) {
        ret += 1;
    }

    cout << ret << endl;

    return 0;
}