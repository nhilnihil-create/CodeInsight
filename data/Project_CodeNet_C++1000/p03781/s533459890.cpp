#include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;

    int res = 1;
    while(true) {
        if(res * (res + 1) / 2 < X) ++res;
        else break;
    }
    cout << res << endl;
}