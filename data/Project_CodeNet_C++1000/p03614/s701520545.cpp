#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
const int MAXN = 234567;
bool a[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int tmp;
        scanf("%d", &tmp);
        a[i] = (tmp == i);
    }
    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (a[i] && a[i + 1]) {
           ans++;
           a[i] = a[i + 1] = false;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (a[i]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
