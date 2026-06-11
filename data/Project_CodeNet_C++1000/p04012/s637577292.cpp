// https://atcoder.jp/contests/abc044/tasks/abc044_b
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
    string w;
    cin >> w;
    map<char, int> cnts;
    for (int i = 0; i < w.size(); ++i)
    {
        ++cnts[w[i]];
    }
    for (const auto& e : cnts)
    {
        if (e.second % 2 != 0)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
