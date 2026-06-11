#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[] = {1, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};

const int Maxn = 20010;

int a[Maxn], b[Maxn];

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        a[i] = b[n - 1 - i] = (i + 1) * n;
    }
    int x;
    cin >> x;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x;
        --x;
        a[x] += i + 1;
    }
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << " ";
        cout << b[i];
    }
    cout << endl;
}
