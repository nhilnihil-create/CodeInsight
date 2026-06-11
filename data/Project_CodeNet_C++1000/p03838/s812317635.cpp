#include <bits/stdc++.h>
using namespace std;

int main() {
    long long X, Y; cin >> X >> Y;
    long long ans = abs(abs(X) - abs(Y));
    if (abs(X) > abs(Y)) {
        if (X < 0) X += ans;
        else {
            X -= ans;
            X *= -1;
            ans++;
        }
    } 
    else {
        if (X < 0) {
            X -= ans;
            ans++;
            X *= -1;
        }
        else X += ans;
    }
    
    if (X * -1 == Y && (X != 0 && Y != 0)) ans++;
    cout << ans << endl;
}