#include <iostream>

using namespace std;

int main(){
    int H, W, d;
    cin >> H >> W >> d;
    char c[500][500];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int x = i+j;
            int y = i-j;
            int X, Y;
            if(x < 0 && x%d != 0) X = x/d-1;
            else X = x/d;
            if(y < 0 && y%d != 0) Y = y/d-1;
            else Y = y/d;
            //cout << X << ' ' << Y;
            if(X%2 == 0 && Y%2 == 0) cout << 'R';
            if(X%2 == 0 && Y%2 != 0) cout << 'Y';
            if(X%2 != 0 && Y%2 == 0) cout << 'G';
            if(X%2 != 0 && Y%2 != 0) cout << 'B';
        }
        cout << endl;
    }
}