#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

int main() {
    LL X, Y;
    scanf("%lld %lld", &X, &Y);
    if (abs(X - Y) < 2) puts("Brown");
    else puts("Alice");
    return 0;
}
