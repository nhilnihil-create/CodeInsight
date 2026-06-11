#include <bits/stdc++.h>

using namespace std;

void printSharpLine(int n) {
    for (int i = 0; i < n; i++) {
        cout << "#";
    }
    cout << endl;
}


int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> data(h, vector<char>(w, 0));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> data.at(i).at(j);
        }
    }

    printSharpLine(w + 2);

    for (int i = 0; i < h; i++) {
        cout << "#";
        for (int j = 0; j < w; j++) {
            cout << data.at(i).at(j);
        }
        cout << "#" << endl;
    }

    printSharpLine(w + 2);

    return 0;
}
