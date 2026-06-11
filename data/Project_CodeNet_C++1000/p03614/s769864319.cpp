#include<bits/stdc++.h>
#define N 500000
using namespace std;
int n, a[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int nx = (i + 1 <= n) ? i + 1 : 1;
        if (a[i] == i) swap(a[i], a[nx]), ans++;
    }
    cout << ans << endl;
}
