#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64_t x;
    cin >> x;

    int64_t sum = 0;

    for (int i = 1; i <= x; i++) {
        sum += i;
        if (sum >= x) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}

