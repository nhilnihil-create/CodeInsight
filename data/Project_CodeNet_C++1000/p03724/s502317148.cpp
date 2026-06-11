#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>

using namespace std;

const int MAXN = 100000;

int parity[1 + MAXN];

int main () {
    //ifstream cin("input.in");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        parity[a] ^= 1;
        parity[b] ^= 1;
    }
    for (int i = 1; i <= n; i++)
        if (parity[i]) {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
    return 0;
}



