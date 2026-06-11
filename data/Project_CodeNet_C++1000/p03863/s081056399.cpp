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
    const int n = S.size();
    int removed = 0;
    char last = 'A';
    for (int i = 0;i + 1 < n;) {
        int j = i + 2;
        while (j < n && S[j] == S[j - 2])
            j++;

        // j == n or a[j] != a[j - 2]
        if (j == n)
            break;
        removed += j - i - 1;
        S[j - 1] = S[i];
        i = j - 1;
    }

    cout << (removed % 2 == 1 ? "First" : "Second") << endl;
    return 0;
};
