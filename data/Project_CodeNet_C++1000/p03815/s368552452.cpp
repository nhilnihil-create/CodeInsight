#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int x;
    cin >> x;
    int X = (x/11)*2;
    int Y = x%11;
    if(Y != 0 && Y <= 6) {
        X++;
    }
    else if(Y != 0 && Y < 11){
        X+=2;
    }
    cout << X << endl;
}
