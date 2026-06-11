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

int arr[100];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d", arr + i);
        if (arr[i] & 1) ++cnt;
    }
    if (m == 1) {
        if (arr[0] == 1) {
            printf("1\n1\n1\n");
            return 0;
        }
        printf("%d\n2\n%d 1\n", arr[0], arr[0] - 1);
        return 0;
    }
    if (cnt > 2) {
        printf("Impossible\n");
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        if (arr[i] & 1) {
            swap(arr[0], arr[i]);
            break;
        }
    }
    for (int i = m; --i; ) {
        if (arr[i] & 1) {
            swap(arr[m - 1], arr[i]);
            break;
        }
    }
    for (int i = 0; i < m; ++i) printf("%d ", arr[i]);
    printf("\n%d\n", m - (arr[0] == 1));
    if (arr[0] - 1) printf("%d ", arr[0] - 1);
    for (int i = 1; i + 1 < m; ++i) printf("%d ", arr[i]);
    printf("%d\n", arr[m - 1] + 1);
	return 0;
}
