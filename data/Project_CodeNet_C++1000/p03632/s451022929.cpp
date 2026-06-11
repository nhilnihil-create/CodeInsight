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
#define int long long
using namespace std;
signed main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if (B <= C) {
        cout << 0 << endl;
    }
    else if (D <= A) {
        cout << 0 << endl;
    }
    else if(A>=C&&B<=D){
        cout << B - A << endl;
    }
    else if (A <= C && B >= D) {
        cout << D - C << endl;
    }
    else if (A < D && C < B && D < B && C < A) {
        cout << D - A << endl;
    }
    else {
        cout << B-C << endl;
    }
}