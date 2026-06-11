# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;


int n, x;
int a[200005];
bool used[200005];

int main(int argc, const char * argv[]) {
    #ifdef __APPLE__
        freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
        //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    int m = n + n - 1;
    if (m == 3) {
        if (x == 2) {
            cout << "Yes\n1\n2\n3\n";
            return 0;
        } else {
            cout << "No\n";
            return 0;
        }
    }
    if (x == 1 || x == m) {
        cout << "No\n";
        return 0;
    }
    for (int i = -1; i <= 1; ++i) {
        a[n + i] = x + i;
        used[x + i] = true;
    }
    int last = 1;
    for (int i = 1; i <= m; ++i) if (i < n - 1 || i > n + 1) {
        while (used[last])
            ++last;
        used[last] = true;
        a[i] = last;
    }
    cout << "Yes\n";
    for (int i = 1; i <= m; ++i)
        cout << a[i] << '\n';
    return 0;
}

