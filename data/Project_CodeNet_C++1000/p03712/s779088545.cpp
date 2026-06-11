#include <bits/stdc++.h>
using namespace std;

int main() {
        int H, W;
        cin >> H >> W;
        string str[H];

        for (int i = 0; i < H; i++) {
                cin >> str[i];
        }
        string ig(W+2,'#');
        cout <<ig << endl;
        for (int i = 0; i < H; i++) {
                cout << '#' << str[i] << '#' << endl;
        }
        cout <<ig << endl;

}