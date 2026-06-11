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


ll fact(ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        res = (res * n) % mod;
        --n;
    }
    return res;
}

int main() {
    int task = 1;
//    cin >> task;
    while (task--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << a + b + c - max(a, max(b, c)) << "\n";
    }

    return 0;
}