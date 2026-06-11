#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    string a;
    cin >> h >> w;
    
    
    for (int i = 0; i < w + 2; i++) {
        cout << '#';
    }
    cout << endl;

    for (int i = 0; i < h; i++) {
        cin >> a;
        cout << '#' << a << '#' << endl;
    }

    for (int i = 0; i < w + 2; i++) {
        cout << '#';
    }
    cout << endl;

}
