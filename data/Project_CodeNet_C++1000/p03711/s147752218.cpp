#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int xg, yg;
    if(x==2) {
        xg = 2;
    } else if(x==4 || x==6 || x==9 || x==11) {
        xg = 4;
    } else {
        xg = 1;
    }
    if(y==2) {
        yg = 2;
    } else if(y==4 || y==6 || y==9 || y==11) {
        yg = 4;
    } else {
        yg = 1;
    }
    if(xg==yg) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
    
}