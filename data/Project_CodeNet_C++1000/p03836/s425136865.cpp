/**
 *    author:  FromDihPout
 *    created: 2020-06-23
**/

#include <bits/stdc++.h>
using namespace std;


void move(int start, int end, bool vertical) {
    char c;
    if (vertical && start < end) 
        c = 'U';
    else if (vertical)
        c = 'D';
    else if (start < end)
        c = 'R';
    else
        c = 'L';
        
    int a = min(start, end), b = max(start, end);
    for (int i = a + 1; i <= b; i++) {
        cout << c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    
    move(sy, ty, true);
    move(sx, tx, false);
    
    move(ty, sy, true);
    move(tx, sx, false);
    
    move(sx, sx - 1, false);
    move(sy, ty + 1, true);
    move(sx - 1, tx, false);
    move(ty + 1, ty, true);
    
    move(tx, tx + 1, false);
    move(ty, sy - 1, true);
    move(tx + 1, sx, false);
    move(sy - 1, sy, true);
    
    return 0;
}