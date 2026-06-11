#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>
#include <cmath>
#include <functional>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
const int M = 1e9 + 7;
const int N = 5e6 + 100;
const int MAX = 1e9 + 1;
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

ll a[50];
int main() {
    int i, j;
    ll k;
    cin >> k;
    ll t = k / 50LL;
    for (i = 0; i < 50; ++i)
        a[i] = 49LL + 51LL * t - k;
    for (i = 0; i < (int)(k % 50LL); ++i)
        a[i] += 51LL;
    cout << 50 << endl;
    for (i = 0; i < 50; ++i)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
