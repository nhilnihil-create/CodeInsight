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
    bool n = false, s = false, w = false, e = false;
    string str;
    cin >> str;
    for (auto c : str) {
        if (c == 'N') {
            n = true;
        } else if (c == 'W') {
            w = true;
        } else if (c == 'E') {
            e = true;
        } else {
            s = true;
        }
    }
    if ((n ^ s) || (w ^ e)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}


