#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n, 0);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        cnt[a]++; cnt[b]++;
    }
    int odd = 0;
    for (int i = 0; i < n; i++) if (cnt[i] % 2) odd++;
    if (odd) cout << "NO" << endl;
    else cout << "YES" << endl;
}