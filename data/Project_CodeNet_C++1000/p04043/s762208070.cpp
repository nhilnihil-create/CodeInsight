#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    vector<int> cnts(100, 0);

    for (int i = 0; i < 3; ++i) {
        int x;
        cin >> x;
        ++cnts[x];
    }

    if (cnts[5] == 2 && cnts[7] == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}