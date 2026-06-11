#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctype.h>
using namespace std;
#define dump(a) cout << (a) << '\n';
typedef long long Int;
Int mod = 1e9+7;
Int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    Int n;
    cin >> n;
    Int sum = 0;
    Int i = 1;
    while (sum < n) {
        sum += i;
        i++;
    }
    for (Int j = 1; j < i; j++) {
        if (j == sum - n) continue;
        dump(j);
    }
    return 0;  
}