#include <bits/stdc++.h>
using namespace std;

int w, a, b;

void solve() {
    cin >> w >> a >> b;
    if(b < a) swap(a, b);
    cout << (b - a - w <= 0 ? 0 : b - a - w) << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}