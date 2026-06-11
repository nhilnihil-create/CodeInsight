#include <iostream>
using namespace std;

int w, a, b;

void solve() {
    cin >> w >> a >> b;
    if(a > b) swap(a, b);
    cout << (a + w >= b ? 0 : b - (w + a)) << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}