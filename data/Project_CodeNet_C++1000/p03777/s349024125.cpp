#include <bits/stdc++.h>
using namespace std;

char a, b;

void solve() {
    cin >> a >> b;
    cout << ((a == 'H' && b == 'H') || (a == 'D' && b == 'D') ? "H\n" : "D\n"); 
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}