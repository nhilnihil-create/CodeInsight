#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int x, y; cin >> x >> y;
    if(x == 2 && y == 2){
        cout << "Yes" << endl;
        return 0;
    }
    int a[] = {4, 6, 9, 11};
    bool xf = false, yf = false;
    for(int i = 0; i < 4; i++){
        if(x == a[i]) xf = true;
        if(y == a[i]) yf = true;
    }
    if(xf && yf){
        cout << "Yes" << endl;
        return 0;
    }
    int b[] = {1, 3, 5, 7, 8, 10, 12};
    xf = false, yf = false;
    for(int i = 0; i < 7; i++){
        if(x == b[i]) xf = true;
        if(y == b[i]) yf = true;
    }
    if(xf && yf){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
