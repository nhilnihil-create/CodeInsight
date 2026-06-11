#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    string s;
    vector<string> a(h);

    for (int i = 0; i < h; ++i) {
        cin >> a.at(i);
    }

    for (int j = 0; j < w + 2; ++j) {
        cout << "#";
    }
    cout << endl;

    for (string x:a) {
        cout << "#" << x << "#" << endl;
    }

    for (int j = 0; j < w + 2; ++j) {
        cout << "#";
    }
    cout << endl;

    return 0;
}