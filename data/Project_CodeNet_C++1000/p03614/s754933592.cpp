#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <map>
#include <sstream>
#include <bitset>
#include <random>
#include <tuple>
#include <array>
#include <tgmath.h>
#include <functional>
#include <climits>
#include <complex>
#include <unistd.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

int arr[100100];

int main() {
    int s = 0, n, t, c = 0;
    scanf("%d", &n);
    int i;
    for (i=1; i<=n; ++i) {
        scanf("%d", &t);
        if (t == i) ++c;
        else {
            s += -~c/2;
            c = 0;
        }
    }
    printf("%d\n", s + -~c/2);
    return 0;
}
