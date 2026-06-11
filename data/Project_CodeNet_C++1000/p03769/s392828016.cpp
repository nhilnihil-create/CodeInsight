#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int N = 210;
int a[N];

int main() {
    LL n;
    cin >> n;
    int mx = 0; 
    while ((1ll<<mx)-1 <= n) mx++;
    mx--;
    n -= (1ll<<mx) - 1;
    int cur = 100;
    for (int i = 1; n; i++) {
        if (n & 1) a[i] = cur--;
        n >>= 1;
    }
    vector<int> ans;
    for (int i = 1; i <= mx; i++) {
        if (a[i]) ans.push_back(a[i]);
        ans.push_back(i);
    }
    for (int i = 1; i <= mx; i++) ans.push_back(i);
    for (int i = cur + 1; i <= 100; i++) ans.push_back(i);
    printf("%d\n", ans.size());
    for (int i = 0; i < int(ans.size()); i++) printf("%d%c", ans[i], " \n"[i == int(ans.size()) - 1]);
    return 0;
}
