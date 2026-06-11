#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>


using std::cout;
using std::cin;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


ll gcd(ll a, ll b) {
    while (b != 0) {
        auto tmp = a;
        a = b;
        b = tmp % a;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}




void oneCase () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(n, 1e9));
    vector<int> a(m);
    vector<int> b(m);
    vector<int> c(m);
    for (int i = 0; i < m; ++i ) {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        d[x][y] = z;
        d[y][x] = z;
        c[i] = z;
        a[i] = x;
        b[i] = y;
        d[x][x] = 0;
        d[y][y] = 0;
    }
    for (int mid = 0; mid < n; ++mid) {
        for (int l = 0; l < n; ++l) {
            for (int r = 0; r < n; ++r) {
                d[l][r] = min(d[l][r], d[l][mid] + d[mid][r]);
            }
        }
    }
    int res = m;
    for (int i = 0; i < m; ++i) {
        bool sh = false;
        for (int mid = 0; mid < n; ++mid) {
            if (c[i] == d[a[i]][mid] - d[mid][b[i]]) {
                sh = true;
                break;
            }
        }
        if (sh) {
            --res;
        }
    }
    cout << res << "\n";
}





int main() {
    int t = 1;
//    cin >> t;
    while (t > 0) {
        oneCase();
        --t;
    }

    return 0;
}