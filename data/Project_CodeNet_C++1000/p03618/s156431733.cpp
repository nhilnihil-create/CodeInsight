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
typedef vector<s32> vs32;
typedef vector<u32> vu32;
typedef vector<s64> vs64;
typedef vector<u64> vu64;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

bool is_kaibun(string& s)
{
    bool ret = true;
    rep (i, s.size() / 2)
    {
        if (s[i] != s[s.size() - i - 1]) ret = false;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    vs64 cnt(26, 0);
    s64 n = s.size();
    rep (i, n)
    {
        ++cnt[s[i] - 'a'];
    }

    s64 ans = 0;
    rep (i, 26)
    {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << n * (n - 1) / 2 + 1 - ans << "\n";
    return 0;
}

