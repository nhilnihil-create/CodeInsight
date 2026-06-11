#include <iostream>
#include <vector>
using namespace std;
int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int flag = 0, flag2 = 0;
    if(sx > tx) flag = 1;
    if(sy > ty) flag2 = 1;
    char c[4] = {'U', 'R', 'D', 'L'};
    for(int i = 0; i < abs(tx - sx); i++){
        if(flag) cout << c[3];
        else cout << c[1];
    }
    for(int i = 0; i < abs(ty - sy); i++){
        if(flag2) cout << c[2];
        else cout << c[0];
    }
    for(int i = 0; i < abs(tx - sx); i++){
        if(flag) cout << c[1];
        else cout << c[3];
    }
    for(int i = 0; i < abs(ty - sy) + 1; i++){
        if(flag2) cout << c[0];
        else cout << c[2];
    }
    for(int i = 0; i < abs(tx - sx) + 1; i++){
        if(flag) cout << c[3];
        else cout << c[1];
    }
    for(int i = 0; i < abs(ty - sy) + 1; i++){
        if(flag2) cout << c[2];
        else cout << c[0];
    }
    if(flag) cout << c[1];
    else cout << c[3];
    if(flag2) cout << c[2];
    else cout << c[0];
    for(int i = 0; i < abs(tx - sx) + 1; i++){
        if(flag) cout << c[1];
        else cout << c[3];
    }
    for(int i = 0; i < abs(ty - sy) + 1; i++){
        if(flag2) cout << c[0];
        else cout << c[2];
    }
    if(flag) cout << c[3];
    else cout << c[1];
    cout << endl;
}