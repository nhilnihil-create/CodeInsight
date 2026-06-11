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
#include <deque>
#include <numeric>

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

#define IN(l, r, x) ((l) <= (x) && (x) < (r))

// AGC016 B

bool solve(const vs32& a, int num)
{
    const int n = a.size();

    int cnt = 0;
    rep (i, n)
    {
        if (a[i] != num)
        {
            ++cnt;
        }
    }

    return cnt + 1 == num || (cnt < num && (num - cnt) * 2 <= (n - cnt));
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vs32 a(n);
    set<int> s;
    rep (i, n)
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    if (s.size() >= 3)
    {
        cout << "No\n";
    }
    else if (s.size() == 2 && abs(*s.begin() - *s.rbegin()) >= 2)
    {
        cout << "No\n";
    }
    else if (s.size() == 2)
    {
        int num = *s.rbegin();
        if (solve(a, num))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    else // all a are equal
    {
        int num = *s.begin();
        if (n == num + 1)
        {
            cout << "Yes\n";
        }
        else if (2 * num <= n)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
        
    }

    return 0;
}

