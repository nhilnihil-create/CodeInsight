#include <bits/stdc++.h>
using namespace std;

int main()
{

        int sx, sy;
        int tx, ty;
        cin >> sx >> sy >> tx >> ty;

        int dx = abs(sx - tx);
        int dy = abs(sy - ty);

        for (int i = 0; i < dy; ++i) {
                cout << 'U';
        }
        for (int i = 0; i < dx; ++i) {
                cout << 'R';
        }
        for (int i = 0; i < dy; ++i) {
                cout << 'D';
        }
        for(int i = 0;i < dx; ++i) {
                cout << 'L';
        }
        cout << 'L';
        for (int i = 0; i < dy+1; ++i) {
                cout << 'U';
        }
        for (int i = 0; i < dx+1; ++i) {
                cout << 'R';
        }
        cout << 'D';
        cout << 'R';
        for (int i = 0; i < dy+1; ++i) {
                cout << 'D';
        }
        for(int i = 0; i < dx+1; ++i) {
                cout << 'L';
        }
        cout << 'U';
}
