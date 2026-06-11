#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	char col[5] = "RYGB";
	int h, w, d;
	cin >> h >> w >> d;
	for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            printf("%c", col[((i + j) / d & 1) << 1 | ((i - j + w) / d & 1)]);
        }
        printf("\n");
	}
	return 0;
}
