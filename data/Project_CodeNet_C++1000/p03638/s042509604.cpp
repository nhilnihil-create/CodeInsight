#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


// 68 11 55 - rank 3
// 69 12 19

int gcd(int a, int b) {
    while (b != 0) {
        auto na = a % b;
        a = b;
        b = na;
    }
    return a;
}


void oneCase() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    for (auto& e : a) {
        cin >> e;
    }
    int color = 0;
    int id = 0;
    vector<vector<int>> b(h, vector<int>(w, 0));
    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c) {
            auto column = c;
            if (r % 2 == 1) {
                column = w - c - 1;
            }
            if (color == a[id]) {
                ++id;
                color = 0;
            }
            b[r][column] = id;
            ++color;
        }
    }

    for (auto& row : b) {
        for (auto el : row) {
            cout << el + 1<< " ";
        }
        cout << "\n";
    }
}


int main() {
    int t = 1;
//    cin >> t;
    while (t--) {
       oneCase();
    }

    return 0;
}

ll fact(ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        res = (res * n) % mod;
        --n;
    }
    return res;
}
