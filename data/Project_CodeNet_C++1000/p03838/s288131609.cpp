

#include <bits/stdc++.h>

using namespace std;

int _x;
int _y;
int _ans;

void CParseIn () {
    cin >> _x >> _y;
}

int Calc (int x, int y) {
    if (x <= y) {
        return y - x;
    }
    
    return x - y + 2;
}

void Core () {
    _ans = min(Calc(_x ,_y),min(Calc(-_x,_y)+1,min(Calc(_x,-_y)+1,Calc(-_x,-_y)+2)));
}

void CWriteOut () {
    cout << _ans << endl;
}

int main () {
    
    CParseIn();
    Core();
    CWriteOut();
    
    return 0;
}