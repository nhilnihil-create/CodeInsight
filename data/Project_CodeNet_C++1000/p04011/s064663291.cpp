#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k,x,y; cin >> n >> k >> x >> y;
    if (n < k) {
        cout << n * x << endl;
    }
    else {
        cout << k * x + (n - k) * y << endl; 
    }
    


}