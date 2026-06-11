#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

vector<int> x = vector<int>(26, 0);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    char c;
    rep (i, H * W)
    {
        cin >> c;
        ++x[c - 'a'];
    }

    int thres;
    bool odd;
    if ((H & 1) && (W & 1))
    {
        thres = (H - 1) * (W - 1) / 4;
        odd = true;
    }
    else if (!(H & 1) && !(W & 1))
    {
        thres = H * W / 4;
        odd = false;
    }
    else if (H & 1)
    {
        thres = (H - 1) * W / 4;
        odd = false;
    }
    else
    {
        thres = H * (W - 1) / 4;
        odd = false;
    }

    int acc = 0;
    bool ans = true;
    for (int i = 0; i < x.size() && ans; ++i)
    {
        acc += x[i] / 4;
        if (x[i] & 1)
        {
            if (!odd)
            {
                ans = false;
            }
            odd = false;
        }
    }
    if (acc < thres) ans = false;

    if (ans) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

