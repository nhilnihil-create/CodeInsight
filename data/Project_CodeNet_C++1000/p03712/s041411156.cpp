#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    cin.ignore(); /* skip remained '\n' */

    vector<string> s(h);
    for (int i = 0; i < h; i++)
        cin >> s.at(i);

    cout << string(w + 2, '#') << endl;

    for (int i = 0; i < h; i++) {
        cout << "#";
        cout << s.at(i);
        cout << "#" << endl;
    }

    cout << string(w + 2, '#') << endl;
}