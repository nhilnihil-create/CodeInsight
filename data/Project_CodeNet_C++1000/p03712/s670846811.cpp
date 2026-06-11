#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    string c;
    for (int i = 0 ; i < W + 2; i++){
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < H ; i++){
        cin >> c;
        cout << "#" << c << "#" << endl;
    }
    for (int i = 0; i < W + 2; i++){
        cout << "#";
    }
}