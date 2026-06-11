#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 200005;

int n, m, a[N];
ll b[N], r;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        if(i > 1){
            int x = a[i - 1], y = a[i];
            if(x > y) y += m;
            r += (y - x);
            b[x + 2]++;
            b[y + 1] -= (y - x);
            b[y + 2] += (y - x - 1);
        }
    }
    for(int i = 1; i <= 2 * m; i++) b[i] += b[i - 1];
    for(int i = 1; i <= 2 * m; i++) b[i] += b[i - 1];
    for(int i = 1; i <= m; i++) b[i] += b[m + i];
    printf("%lld\n", r - *max_element(b + 1, b + m + 1));
}