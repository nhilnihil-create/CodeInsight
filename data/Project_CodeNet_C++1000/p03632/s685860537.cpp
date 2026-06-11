#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++); 
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int cnt = 0;
    bool alice = false;
    bool bob = false;

    for (int i = 0; i < 100; ++i) {
        if (a == i) alice = true;
        else if (b == i) alice = false;

        if (c == i) bob = true;
        else if (d == i) bob = false;

        if (alice==true && bob==true) ++cnt;
    }

    cout << cnt << endl;

}