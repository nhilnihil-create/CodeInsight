#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll x, y;
    cin >> x >> y;
    if(x >= 0 && y >= 0){
        if(x <= y)cout << y - x << endl;
        else {
            if(y == 0)cout << x - y + 1 << endl;
            else cout << x - y + 2 << endl;
        }
    }else if(x >= 0 && y < 0){
        if(x < abs(y))cout << abs(y) - x + 1<< endl;
        else cout << x - abs(y) + 1 << endl;
    }else if(x < 0 && y >= 0){
        if(abs(x) < y)cout << y - abs(x) + 1 << endl;
        else if(y == 0)cout << abs(x) << endl;
        else cout << abs(x) - y + 1 << endl;
    }else{
        if(abs(x) < abs(y))cout << abs(y) - abs(x) + 2 << endl;
        else cout << abs(x) - abs(y) << endl;
    }
    return 0;
}
