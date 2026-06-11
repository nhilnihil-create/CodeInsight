#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 4e5;
int a[N + 3];
int d[N + 3];
int dp[N + 3][10];
vector<int> b;
int n;
bool cmp(int x, int y) { 
    return x > y; 
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, cmp);
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= i && a[i + 1] <= i) {
            pos = i;
            break;
        }
    }
    int len1 = 0;
    for (int i = pos + 1; i <= n; i++) {
        if (a[i] > pos - 1)
            len1++;
    }
    int len2 = a[pos] - pos;
    if ((!(len1 & 1)) && (!(len2 & 1)))
        printf("Second");
    else
        printf("First");
    return 0;
}