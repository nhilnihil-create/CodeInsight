#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c) {
        cout << 1 << endl;
        return 0;
    }
    if (a == b || b == c || a == c) {
        cout << 2 << endl;
        return 0;
    }
    cout << 3 << endl;
}
