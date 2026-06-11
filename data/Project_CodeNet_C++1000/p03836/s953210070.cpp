#include <iostream>
using namespace std;
int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int y = tx - sx, t = ty - sy;
    for(int i=0; i<t; i++){
        cout << "U";
    }
    for(int i=0; i<y; i++){
        cout << "R";
    }
    for(int i=0; i<t; i++){
        cout << "D";
    }
    for(int i=0; i<y; i++){
        cout << "L";
    }
    cout << "L";
    for(int i=0; i<t+1; i++){
        cout << "U";
    }
    for(int i=0; i<y+1; i++){
        cout << "R";
    }
    cout << "DR";
    for(int i=0; i<t+1; i++){
        cout << "D";
    }
    for(int i=0; i<y+1; i++){
        cout << "L";
    }
    cout << "U" << endl;
    return 0;
}