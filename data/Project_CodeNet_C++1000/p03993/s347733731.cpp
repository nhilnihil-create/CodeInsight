#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

int n, sol;
int a[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        sol += a[a[i]] == i;
    }
    cout << sol / 2;
    return 0;
}
