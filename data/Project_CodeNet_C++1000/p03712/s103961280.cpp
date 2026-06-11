#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int h, w;
    cin >> h >> w;
    cout << string(w + 2, '#') << endl;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        cout << "#" + s + "#" << endl;
    }
    cout << string(w + 2, '#') << endl;
    return 0;
}