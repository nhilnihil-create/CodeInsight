#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int H,W;
    cin >> H >> W;
    char S[H][W];
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> S[i][j];
        }
    }
    
    for(int i=0;i<H;i++){
        for(int k=0;k<2;k++){
            for(int j=0;j<W;j++){
                if(j != W-1) cout << S[i][j];
                else cout << S[i][j] << endl;
            }
        }
    }
}