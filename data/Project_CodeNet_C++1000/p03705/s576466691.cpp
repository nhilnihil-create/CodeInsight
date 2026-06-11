#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    ll a, b;
    cin >> n >> a >> b;
    if (b < a) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        if (a == b) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
        return 0;
    }
    if (n == 2) {
        cout << b - a + 1 << endl;
        return 0;
    }
    cout << (b * (n - 1) + a) - (b + a * (n - 1)) + 1 << endl;
    return 0;
}