#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
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

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N, A, B;
    cin >> N >> A >> B;
    int n = N;
    VEC(int) X(N);
    READVEC(X);
    VEC(lint) dp(N + 1);
    dp[N - 1] = 0;
    dp[N - 2] = min(B * 1LL,  A * 1LL * (X[n - 1] - X[n - 2]));
    FORD(i, N - 3, -1) {
        dp[i] = min(B * 1LL, A * 1LL * (X[i + 1] - X[i])) + dp[i + 1];
        dp[i] = min(dp[i], B + A * 1LL * (X[n - 1]- X[i + 1]));
    }

    cout << dp[0] << endl;
    return 0;
};
