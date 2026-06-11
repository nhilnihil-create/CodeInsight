// https://atcoder.jp/contests/abc062/tasks/abc062_b
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
    int H, W;
    cin >> H >> W;
    H += 2, W += 2;
    vector<vector<char>> a(H, vector<char>(W));
    REP(i, W) a[0][i] = '#', a[H - 1][i] = '#';
    for (int i = 1; i < H - 1; ++i)
    {
        a[i][0] = '#', a[i][W - 1] = '#';
        for (int j = 1; j < W - 1; ++j)
        {
            cin >> a[i][j];
        }
    }
    REP(i, H)
    {
        REP(j, W)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;

}
