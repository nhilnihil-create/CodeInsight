#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong x, y;

int main() {
    cin >> x >> y;

    if (llabs(x - y) > 1) {
        cout << "Alice" << endl;
    }
    else {
        cout << "Brown" << endl;
    }

    return 0;
}
