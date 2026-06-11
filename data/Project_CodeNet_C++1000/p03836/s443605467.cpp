#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visit[3000][3000];
int offsetx = 1500;
int offsety = 1500;

int main()
{
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx;
    int dy = ty - sy;
    vector<char> res;

    for (int x = 0; x < dx; ++x)
    {
        res.push_back('R');
    }
    for (int y = 0; y < dy; ++y)
    {
        res.push_back('U');
    }
    for (int x = 0; x < dx; ++x)
    {
        res.push_back('L');
    }
    for (int y = 0; y < dy; ++y)
    {
        res.push_back('D');
    }
    res.push_back('D');
    for (int x = 0; x < dx + 1; ++x)
    {
        res.push_back('R');
    }
    for (int y = 0; y < dy + 1; ++y)
    {
        res.push_back('U');
    }
    res.push_back('L');

    res.push_back('U');
    for (int x = 0; x < dx + 1; ++x)
    {
        res.push_back('L');
    }
    for (int y = 0; y < dy + 1; ++y)
    {
        res.push_back('D');
    }
    res.push_back('R');

    for (const auto& c : res)
    {
        cout << c;
    }
    cout << endl;
    return 0;
}
