#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

const int MOD = (int)(1e9 + 7);

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 1, num = 0;
    for (int i = 0; i < n; i++) {
        int xi;
        scanf("%d", &xi);
        while (xi < 2 * num) {
            ans = ans * 1ll * num % MOD;
            num --;
        }
        if (xi == 2 * num) {
            ans = ans * 1ll * (num + 1) % MOD;
        } else {
            num ++;
        }
    }
    while (num > 0) {
        ans = ans * 1ll * num % MOD;
        num--;
    }
    printf("%d\n", ans);
}
