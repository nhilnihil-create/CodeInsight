#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <functional>
#include <ctime>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
unsigned euclidean_gcd(unsigned a, unsigned b) {
    if (a < b) return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
using namespace std;

int main() {
    string a;
    cin >> a;
    int e = 1000;
    int g = a.size();
    for (int i = 0; i < 26; i++) {
        char f = 'a';
        for (int j = 0; j < i; j++) {
            f += 1;
        }
        int y = 0;
        int v = 0;
        for (int j = 0; j < g; j++) {
            if (a.at(j) != f)y++;
            else y = 0;
            v = max(v, y);
        }
        e = min(e, v);
}
    cout << e << endl;
}