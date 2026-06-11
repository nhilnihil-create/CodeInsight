#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;
const double PI = 3.14159265359;

int main()
{
    int N, M; cin >> N >> M;
    vector<int> ballNums(N, 1);
    vector<bool> redExists(N, false);
    redExists[0] = true;
    for (int i = 0; i < M; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        --ballNums[x];
        ++ballNums[y];
        if (redExists[x])
        {
            redExists[y] = true;
            if (ballNums[x] == 0) redExists[x] = false;
        }
    }
    cout << count(redExists.begin(), redExists.end(), true) << endl;
}
