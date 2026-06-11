#include<iostream>
 
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    char c[100][100];
    for (int i=0; i<H ;i++){
        for (int j=0; j<W; j++){
            cin >> c[i][j];
        }
    }
    
    for (int i=0; i<H; i++){
        for (int n=0; n<2; n++){
            for (int j=0; j<W; j++){
                cout << c[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}