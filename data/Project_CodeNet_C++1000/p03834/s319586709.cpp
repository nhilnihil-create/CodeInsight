#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    cin >> a;
    for (char c:a) {
        if (c==',') {
            cout << " ";
            continue;
        }
        cout << c;
    }
    cout << endl;
}