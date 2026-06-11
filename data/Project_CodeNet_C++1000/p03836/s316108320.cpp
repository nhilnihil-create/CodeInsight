#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    for(int i = 0; i < tx - sx; i++){
        cout << 'R';
    }
    for(int i = 0; i < ty - sy; i++){
        cout << 'U';
    }
    for(int i = 0; i < tx - sx; i++){
        cout << 'L';
    }
    for(int i = 0; i < ty - sy; i++){
        cout << 'D';
    }
    cout << 'D';
    for(int i = 0; i <= tx - sx; i++){
        cout << 'R';
    }
    for(int i = 0; i <= ty - sy; i++){
        cout << 'U';
    }
    cout << 'L';
    cout << 'U';
    for(int i = 0; i <= tx - sx; i++){
        cout << 'L';
    }
    for(int i = 0; i <= ty - sy; i++){
        cout << 'D';
    }
    cout << 'R' << endl;
}