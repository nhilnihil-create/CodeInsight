#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, numofpush, light;
    bool tf;
    cin >> n;
    vector<int> a(n + 1);
    vector<bool> lighted(n + 1, false);
    for (int i = 1; i <= n; i++) cin >> a.at(i);
    light = 1;
    lighted.at(1) = true;
    numofpush = 1;
    while(true) {
        light = a.at(light);
        if (light == 2) {
            tf = true;
            break;
        }
        if (lighted.at(light) == true) {
            tf = false;
            break;
        }
        lighted.at(light) = true;
        numofpush++;
    }
    if(tf) cout << numofpush << endl;
    else cout << -1 << endl;
}