//　https://atcoder.jp/contests/abc053/tasks/abc053_b
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    string s;
    cin >> s;
    size_t idxa, idxz;
    for (int i = 0; i < s.size(); ++i)
    {
        if ('A' == s[i])
        {
            idxa = i;
            break;
        }
    }

    for (int i = s.size() - 1; i >= 0; --i)
    {
        if ('Z' == s[i])
        {
            idxz = i;
            break;
        }
    }

    size_t maxlen = idxz - idxa + 1;

    cout << maxlen << endl;
    return 0;
}
