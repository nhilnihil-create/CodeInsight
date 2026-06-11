#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    llong x, y;
    cin >> x >> y;
    if (x % 3 != y % 3) {
        if ((x + 2) % 3 == y % 3) --x;
        else --y;
    }
    if (x != y) printf("Alice\n");
    else printf("Brown\n");
    return 0;
}