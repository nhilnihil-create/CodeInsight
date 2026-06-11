#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    string res = "NO";
    if(a == 7) {
        if(b == 5 && c == 5) {
            res = "YES";
        }
    } else if(b == 7) {
        if(a == 5 && c == 5) {
            res = "YES";
        }
    } else if(c == 7) {
        if(b == 5 && a == 5) {
            res = "YES";
        }
    }
    cout << res << endl;
}