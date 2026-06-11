#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(void){
    int H,W;
    cin >> H >> W;
    char C[H][W];
    rep(i,H)rep(j,W)cin >> C[i][j];
    for(int i=0;i < H*2;i++){
        for(int j=0;j<W;j++){
            cout << C[i/2][j];
        }
        cout << endl;
    }
}
