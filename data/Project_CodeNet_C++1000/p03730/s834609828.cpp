#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >>a >>b >>c;
    string ret = "NO";
    for (int i = 0; i < b; i++) {
        if ( (a*i) % b == c ) {ret = "YES"; break;}
    }
    cout << ret << endl;
    return 0;
}