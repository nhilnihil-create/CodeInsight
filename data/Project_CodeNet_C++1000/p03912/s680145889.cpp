#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, c[N], d[N], r;

int main(){
    scanf("%d%d", &n, &m);
    for(int x; n--; ){
        scanf("%d", &x);
        c[x]++;
        d[x % m]++;
    }
    r += d[0] / 2;
    for(int i = 1, j = m - 1; i <= j; i++, j--){
        if(i == j){ r += d[i] / 2; break; }
        int x = i, y = j;
        if(d[x] < d[y]) swap(x, y);
        r += d[y];
        int p = 0;
        for(int k = x; k < N; k += m) p += c[k] / 2 * 2;
        r += min(p, d[x] - d[y]) / 2;
    }
    printf("%d\n", r);
}