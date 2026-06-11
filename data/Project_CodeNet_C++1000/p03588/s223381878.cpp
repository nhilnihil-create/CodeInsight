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

llong n;
llong a, b;
llong mina, minb;

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        if (mina < a) {
            mina = a;
            minb = b;
        }
    }

    cout << mina + minb << endl;

    return 0;
}
