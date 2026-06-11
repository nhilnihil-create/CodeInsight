#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; string s, t; cin >> n >> s;
    int rc = 0, lc = 0;
    for (auto i = 0; i < n; i++) {
        if(s[i] == '(') rc++;
        else {
            if(rc == 0) lc++;
            else rc--;
        }
    }

    for (auto i = 0; i < lc; i++) t += "(";
    t += s;
    for (auto i = 0; i < rc; i++) t += ")";

    cout << t << endl;
    return 0;
}