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
    string S;
    cin >> S;
    VEC(int) last(26, -1);
    int start = -1, end = -1;
    FOR(i, 0, S.size()) {
        int x = S[i] - 'a';
        if (last[x] >= 0) {
            int total = i + 1 - last[x];
            if (total <= 3) {
                start = last[x] + 1;
                end = i + 1;
                goto done;
            }
        }

        last[x] = i;
    }
done:
    cout << start << " " << end << endl;
    return 0;
};
