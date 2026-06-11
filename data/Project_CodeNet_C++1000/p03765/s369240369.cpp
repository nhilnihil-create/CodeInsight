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
const int MAXN = 123456;
char S[MAXN], T[MAXN];
int hashT[MAXN], hashS[MAXN];

int main() {
    scanf("%s", S + 1);
    scanf("%s", T + 1);
    int lenS = strlen(S + 1), lenT = strlen(T + 1);
    for (int i = 1; i <= lenS; i++) {
        int cur = 1;
        if (S[i] == 'B') cur = 2;
        hashS[i] = (hashS[i - 1] + cur) % 3;
    }
    for (int i = 1; i <= lenT; i++) {
        int cur = 1;
        if (T[i] == 'B') cur = 2;
        hashT[i] = (hashT[i - 1] + cur) % 3;
    }
    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int s = (hashS[b] - hashS[a - 1] + 3) % 3;
        int t = (hashT[d] - hashT[c - 1] + 3) % 3;
        if (s == t) puts("YES");
        else puts("NO");
    }
    return 0;
}
