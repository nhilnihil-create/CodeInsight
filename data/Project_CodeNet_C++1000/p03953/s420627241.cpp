#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 100010;
int n, m, x[M], b[M], a[M], tmp[M], ans[M], t;
ll k;
bool vis[M];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++) {
        scanf("%d", &x[i]);
    }
    scanf("%d%lld", &m,& k);
    for (int i = 1; i < n;i++) {
        b[i] = i;
    }
    for (int i = 1; i <= m;i++) {
        scanf("%d", &a[i]);
        swap(b[a[i]], b[a[i] - 1]);
    }
    for (int i = 1; i < n;i++) {
        if(vis[i]) {
            continue;
        }
        vis[i] = 1;
        t = 1;
        tmp[t] = i;
        for (int j = b[i]; j != i;j=b[j]) {
            vis[j] = 1;
            tmp[++t] = j;
        }
        int tt = k % t;
        for (int j = 1; j <= t;j++) {
            ans[tmp[j]] = tmp[(j - 1 + tt) % t + 1];
        }
     }
     ll sum = x[1];
        printf("%lld\n", sum);
        for (int i = 1; i < n;i++) {
            sum += x[ans[i] + 1] - x[ans[i]];
            printf("%lld\n", sum);
        }
        return 0;
}