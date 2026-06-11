#include <iostream>
#include <sstream>
#include <stack>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
#define PAIR make_pair
#define VEC(type) vector<type >

#define FOR(i, A, B) for(auto i = (A);i != (B); i++)
#define FORD(i, A, B) for(auto i = (A);i != (B); i--)

#define READRANGE(begin, end) FOR(it, begin, end) cin >> *it
#define READVEC(V) READRANGE(BEGIN(V), END(V))

using namespace std;

typedef long long lint;
typedef pair<int, int> Pii;
typedef pair<int, lint> Pil;
typedef pair<lint, lint> Pll;
typedef pair<lint, int> Pli;

// ---- BEGIN LIBRARY CODE ----
// ---- END LIBRARY CODE ----
void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

const int _infinity = 5000;
VEC(int) A, B, C;
int dp[41][401][401];

int f(int i, int a, int b)
{
    if (i == A.size())
        return a == 0 && b == 0 ? 0 : _infinity;

    int& ans = dp[i][a][b];
    if (ans >= 0)
        return ans;

    ans = f(i + 1, a, b);
    if (A[i] <= a && B[i] <= b)
        ans = min(ans, C[i] + f(i + 1, a - A[i], b - B[i]));
    return ans;
}

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    FOR(i, 0, N) {
        int a, b, c;
        cin >> a >> b >> c;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
    }

    memset(dp, -1, sizeof dp);

    int ret = _infinity;
    for (int k = 1;k * Ma <= 400 && k * Mb <= 400; k++)
        ret = min(ret, f(0, k * Ma, k * Mb));

    cout << (ret >= _infinity ? -1 : ret) << endl;
    return 0;
};
