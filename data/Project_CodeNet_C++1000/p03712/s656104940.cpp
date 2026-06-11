#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int H,W;
    cin >> H >> W;
    char s[H][W];
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> s[i][j];
        }
    }
    
    for(int i=0;i<W+2;i++){
        if(i == W+1) cout << '#' <<endl;
        else cout << '#';
    }
    
    for(int i=0;i<H;i++){
        for(int j=-1;j<=W;j++){
            if(j == -1) cout << '#';
            else if(j == W) cout << '#' <<endl;
            else cout << s[i][j];
        }
    }
    
    for(int i=0;i<W+2;i++){
        if(i == W+1) cout << '#' <<endl;
        else cout << '#';
    }
}