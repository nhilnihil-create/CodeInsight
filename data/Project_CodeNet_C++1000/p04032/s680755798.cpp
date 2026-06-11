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

    string S;

    cin >> S;

    int n = S.length();

    int l = -1;
    int r = -1;

    for (int i = 0; i + 1 < n; ++i) {
        if (S[i] == S[i + 1]) {
            l = i;
            r = i + 1;
            break;
        }
        if (i + 2 < n) {
            if (S[i] == S[i + 2]) {
                l = i;
                r = i + 2;
                break;
            }
        }
    }

    if (l >= 0) {
        ++l, ++r;
    }
    cout << l << " " << r << "\n";


    return 0;
}