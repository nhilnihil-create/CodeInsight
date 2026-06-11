#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int H,W;
    cin >> H >> W;
    string s[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) cin >> s[i][j];
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(s[i][j] != "snuke") continue;
            cout << char(j + 'A') << i+1 << endl;
        }
    }

 }