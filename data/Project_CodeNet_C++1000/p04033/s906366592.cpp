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
    int a, b;
    cin >> a >> b;
    if (0 >= a && 0 <= b) {
        cout << "Zero" << endl;
        return 0;
    }
    if (a > 0) {
        cout << "Positive" << endl;
        return 0;
    }
    if (b < 0) {
        a -= b - 1;
    }
    a = abs(a);
    if (a % 2 == 1) {
        cout << "Negative" << endl;
    } else {
        cout << "Positive" << endl;
    }
}


