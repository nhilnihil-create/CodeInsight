#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    string s;
    cin >> s;
    int k = 0;
    int p = 0;
    for (char a: s) {
        char b;
        if (k) {
            b = 'p';
            k--;
        }
        else {
            b = 'g';
            k++;
        }
        if (a != b) {
            if (a == 'g') {
                p++;
            }
            else {
                p--;
            }
        }
    }
    cout << p << endl;
}