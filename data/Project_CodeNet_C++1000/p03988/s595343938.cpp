#include<bits/stdc++.h>
using namespace std;
const int MAXN = 109;

void parbona() {
    cout << "Impossible" << endl;
    exit(0);
}

int done[MAXN];
int a[MAXN];

int findIdx(int n, int x) {
    for (int i = 1; i <= n; i++) {
        if (done[i]) continue;
        if (a[i]==x) return i;
    }
    return -1;
}

int dst[MAXN];
int makeDo(int n, int x) {
    int i = findIdx(n, x);
    if (i==-1) parbona();
    done[i] = 1;
    dst[x] = i;
}

int main() {
    int n;
    cin >> n;

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int d = mx/2;
    if (mx%2==0) makeDo(n, d);
    for (int x = d+1; x <= mx; x++) {
        makeDo(n, x);
        makeDo(n, x);
    }

    for (int i = 1; i <= n; i++) {
        if (done[i]) continue;
        if (a[i] <= d) parbona();
        if (dst[a[i]-1] == 0) parbona();
    }

    cout << "Possible" << endl;

    return 0;
}
