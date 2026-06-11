#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int H, W;
    char c[110][110];
    char c2[210][110];

    cin >> H  >> W;
    for(int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 1; i <= 2*H; i++){
        for(int j = 1; j <= W; j++){
            c2[i][j] = c[(i+1)/2][j];
            cout << c2[i][j];   
        }
        cout << endl;
    }

    return 0;
}