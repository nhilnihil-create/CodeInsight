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

int getroot(VEC(int)& roots, int i)
{
    if (roots[i] == i)
        return i;
    return roots[i] = getroot(roots, roots[i]);
}

void merge(VEC(int)& roots, VEC(int)& sizes, int x, int y)
{
    int rx = getroot(roots, x), ry = getroot(roots, y);
    if (rx == ry)
        return;

    if (sizes[rx] > sizes[ry]) {
        roots[ry] = rx;
    } else if (sizes[rx] < sizes[ry]) {
        roots[rx] = ry;
    } else {
        sizes[rx]++;
        roots[ry] = rx;
    }
}

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N, K, L;
    cin >> N >> K >> L;
    VEC(int) rootA(N), sizeA(N, 1);
    VEC(int) rootB(N), sizeB(N, 1);
    FOR(i, 0, N)
        rootA[i] = rootB[i] = i;

    FOR(i, 0, K) {
        int p, q;
        cin >> p >> q;
        p--;q--;
        merge(rootA, sizeA, p, q);
    }

    FOR(i, 0, L) {
        int p, q;
        cin >> p >> q;
        p--;q--;
        merge(rootB, sizeB, p, q);
    }

    map<int, VEC(int)> groups;
    FOR(i, 0, N)
        groups[getroot(rootA, i)].push_back(i);

    VEC(int) both(N);
    FOR(i, 0, N)
        if (getroot(rootA, i) == i) {
            map<int, vector<int> > bRoots;
            for(int node : groups[i])
                bRoots[getroot(rootB, node)].push_back(node);

            for(auto& pr : bRoots) {
                VEC(int)& gp = pr.second;
                int neighbors = gp.size();
                for(int node : gp)
                    both[node] = neighbors;
            }
        }

    FOR(i, 0, N)
        cout << both[i] << " ";
    cout << endl;
    return 0;
};
