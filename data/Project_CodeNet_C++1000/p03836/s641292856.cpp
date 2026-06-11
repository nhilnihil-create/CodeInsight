#include <bits/stdc++.h>
using namespace std;

int main()
{

        int sx, sy;
        int tx, ty;
        cin >> sx >> sy >> tx >> ty;

        int dx = abs(sx - tx);
        int dy = abs(sy - ty);

        cout << string(dy, 'U');
        cout << string(dx, 'R');
        cout << string(dy, 'D');
        cout << string(dx, 'L');
        cout << 'L';
        cout << string(dy+1, 'U');
        cout << string(dx+1, 'R');
        cout << 'D';
        cout << 'R';
        cout << string(dy+1, 'D');
        cout << string(dx+1, 'L');
        cout << 'U';
}
