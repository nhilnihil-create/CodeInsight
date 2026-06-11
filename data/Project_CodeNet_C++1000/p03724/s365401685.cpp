#include <bits/stdc++.h>
using namespace std;

int r[100001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        r[a]++;
        r[b]++;
    }
    bool yes = true;
    for(int i = 1; i <= n; i++){
        if(r[i]%2 != 0) yes = false;
    }
    if(yes) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}