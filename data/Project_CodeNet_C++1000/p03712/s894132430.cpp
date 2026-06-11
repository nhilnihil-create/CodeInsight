#include <bits/stdc++.h>
using namespace std;

int main(void){
    int h, w;
    cin >> h >> w;
    char pic[h][w];
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            cin >> pic[i][j];
        }
    }
    for (int i=0; i<w+2; i++) cout << '#';
    cout << endl;
    for (int i=0; i<h; i++){
        cout << '#';
        for (int j=0; j<w; j++){
            cout << pic[i][j];
        }
        cout << '#' << endl;
    }
    for (int i=0; i<w+2; i++) cout << '#';
    cout << endl;
    return 0;
}