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

    int a, b;
    cin >> a >> b;
    if (a == 1) {
        a = 14;
    }
    if (b == 1) {
        b = 14;
    }

    if (a > b)  {
        cout << "Alice\n";
    } else if (a == b) {
        cout << "Draw\n";
    } else {
        cout << "Bob\n";
    }


    return 0;
}