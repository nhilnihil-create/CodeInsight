/*
 * Author       : YangDavid
 * Created Time : 2019年07月12日 星期五 11时55分29秒
 */

#include<bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 111111;
int n, m, a[maxn], odd;
vector<int> b;

void output() {
    rep(i, m) printf("%d%c", a[i], " \n"[i == m]);
    int sz = b.size();
    printf("%d\n", sz);
    for(int i = 0; i < sz; ++i)
        printf("%d%c", b[i], " \n"[i == sz - 1]);
    exit(0);
}
void ins(int x) { if(x > 0) b.push_back(x); }

int main() {
    scanf("%d%d", &n, &m);
    rep(i, m) scanf("%d", &a[i]), odd += (a[i] & 1);
    if(odd > 2) { puts("Impossible"); return 0; }
    sort(a + 1, a + m + 1, [](int x, int y) { return (x&1)>(y&1); });

    if(m == 1) { ins(n - 1), ins(1); output(); }
    else if(m == 2) { ins(a[1] - 1), ins(a[2] + 1), output(); }

    if(a[2] & 1) swap(a[2], a[m]);
    for(int i = 1; i <= m; ++i) {
        if(i == 1) ins(a[i] - 1);
        else if(i == m) ins(a[i] + 1);
        else ins(a[i]);
    }
    output();

    return 0;
}
