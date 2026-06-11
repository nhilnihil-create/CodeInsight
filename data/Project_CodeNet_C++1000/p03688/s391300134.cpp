#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, i, a[100003], amin, amax;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    amin = INF;
    amax = 0;
    for (i = 0; i < n; i++) {
        amin = min(amin, a[i]);
        amax = max(amax, a[i]);
    }

    if (amax - amin >= 2) {
        printf("No\n");
        return 0;
    }

    if (amax == amin) {
        if (amin == n - 1 || amin <= n / 2) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
        return 0;
    }

    int b, s, t;
    b = amin;
    s = t = 0;
    for (i = 0; i < n; i++) {
        if (a[i] == b) s++;
        else t++;
    }

    if (b + 1 > s && t >= (b + 1 - s) * 2) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    return 0;
}