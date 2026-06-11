#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> C(H, vector<char>(W));
    rep(0, i, H)
    {
        rep(0, j, W)
        {
            cin >> C.at(i).at(j);
        }
    }

    rep(0, i, 2 * H)
    {
        rep(0, j, W)
        {
            cout << C.at(i / 2).at(j);
        }
        cout << endl;
    }
}