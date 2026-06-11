#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef __int128 lll;
constexpr ll mod = 1000000007;

int main() {
    int n, p, a[200000], b[200000], da[200000], db[200000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        a[p - 1] = b[p - 1] = i;
    }
    for (int i = 1; i < n; i++) {
        da[i] = a[i] - a[i - 1];
        db[i] = b[i - 1] - b[i];
        int o = min(1, min(da[i], db[i])) - 1;
        da[i] -= o;
        db[i] -= o;
    }
    a[0] = 1;
    b[0] = 1000000000;
    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + da[i];
        b[i] = b[i - 1] - db[i];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }
    cout << endl;
}