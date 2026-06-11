#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    long long i, o, t, j, l, s, z;
    cin >> i >> o >> t >> j >> l >> s >> z;
    long long ans = o * 2 + (i / 2) * 4 + (j / 2) * 4 + (l / 2) * 4;
    long long ans2 = 0;
    if((i > 0) && (j > 0) && (l > 0)){
        ans2 = o * 2 + ((i - 1) / 2) * 4 + ((j - 1) / 2) * 4 + ((l - 1) / 2) * 4 + 6;
    }
    cout << max(ans, ans2) / 2 << endl;
    return 0;
}