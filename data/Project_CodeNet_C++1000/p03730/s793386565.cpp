#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> x(b);
    for (int i = 0; i < b; i++) {
        x[i] = a * (i + 1) % b;
    }
    int count = 0;
    for (int i = 0; i < b; i++) {
        if (c == x[i]) {
            count++;
        }
    }
    if (count != 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}