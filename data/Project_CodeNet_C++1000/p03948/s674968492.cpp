#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <utility>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cstring>

using namespace std;

constexpr long long mod = 1000000007;
constexpr double eps = 0.0000000001;

typedef long long ll;
typedef long long unsigned ull;

int main() {
    int n, t, a[100000];
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int c = 1000000000,p = 0;
    for ( int i = 0;i < n;i ++) {
        c = min(c,a[i]);
        p = max(p,a[i]-c);
    }
    c = 1000000000;
    int r = 0;
    for(int i = 0;i < n;i++) {
        c = min(c,a[i]);
        if(a[i] - c == p) r++;
    }
    cout << r << endl;
}