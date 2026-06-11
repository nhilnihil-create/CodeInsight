#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <sstream>
#include <iomanip>
using lint = long long;

int main()
{
    lint sx, sy, tx, ty;
    scanf("%lld", &sx);
    scanf("%lld", &sy);
    scanf("%lld", &tx);
    scanf("%lld", &ty);

    lint dist_x = abs(tx - sx);
    lint dist_y = abs(ty - sy);

    std::string ans = "";
    ans += std::string(dist_x, 'R') + std::string(dist_y, 'U');
    ans += std::string(dist_x, 'L') + std::string(dist_y, 'D');
    ans += std::string(1, 'D') + std::string(dist_x + 1, 'R') + std::string(dist_y + 1, 'U') + std::string(1, 'L');
    ans += std::string(1, 'U') + std::string(dist_x + 1, 'L') + std::string(dist_y + 1, 'D') + std::string(1, 'R');

    std::cout << ans << "\n";

    return 0;
}
