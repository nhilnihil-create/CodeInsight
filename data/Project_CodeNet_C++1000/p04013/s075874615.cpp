#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
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

void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

const int MAXN = 52;
const int MAXS = 2502;
lint dp[MAXN][MAXN][MAXS];

VEC(int) A;
lint f(int i, int count, int sum)
{
    if (i == A.size())
        return count == 0 && sum == 0 ? 1 : 0;

    lint& ans = dp[i][count][sum];
    if (ans >= 0)
        return ans;

    ans = f(i + 1, count, sum);
    if (count >= 1 && sum >= A[i])
        ans += f(i + 1, count - 1, sum - A[i]);
    return ans;
}

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N, avg;
    cin >> N >> avg;
    A.resize(N);
    READVEC(A);

    memset(dp, -1, sizeof dp);
    lint ret = 0;
    FOR(i, 1, A.size() + 1)
        ret += f(0, i, avg * i);
    cout << ret << endl;
    return 0;
};
