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
    int w, h, n;
    cin >> w >> h >> n;
    int x1 = 0, x2 = w, y1 = 0, y2 = h;
    for (int i = 0; i < n; i++) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) {
            x1 = max(x1, x);
            x2 = max(x2, x);
        } else if (a == 2) {
            x1 = min(x1, x);
            x2 = min(x2, x);
        } else if (a == 3) {
            y1 = max(y1, y);
            y2 = max(y2, y);
        } else {
            y1 = min(y1, y);
            y2 = min(y2, y);
        }
    }
    cout << (x2 - x1) * (y2 - y1) << endl;
}


