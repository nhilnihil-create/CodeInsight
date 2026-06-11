#ifdef BUILT_LOCAL

#include "niklib.h"

#endif

#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <cmath>
#include <set>
#include <list>

using namespace std;

typedef long long ll;
constexpr ll mod = 1000000007;

int main() {
    int n, m, a[300][300], r = 300;
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    set<int> c;
    for (int i = 1; i <= m; i++) c.insert(i);
    int b[301];
    while (!c.empty()) {
        for (int i = 1; i <= m; i++) b[i] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (c.find(a[i][j]) != c.end()) {
                    b[a[i][j]]++;
                    break;
                }
        int w = 1;
        for (int i = 1; i <= m; i++) w = max(w, b[i]);
        for (int i = 1; i <= m; i++) if (b[i] == w)c.erase(i);
        r = min(r, w);
    }
    cout << r << endl;
}