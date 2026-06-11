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

// ---- BEGIN LIBRARY CODE ----
// ---- END LIBRARY CODE ----
void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    lint X;
    cin >> X;
    lint first = max(X - 100, 0LL);
    // t * 11 >= first.
    lint t = first == 0 ? 0 : (first - 1) / 11 + 1;
    lint ret = t * 2;
    t *= 11;
    int sideUp = 6;
    while (t + 11 < X) {
        t += 11;
        ret += 2;
    }

    // t + 11 >= X
    if (t + 6 >= X)
        ret++;
    else ret += 2;
    cout << ret << endl;
    return 0;
};
