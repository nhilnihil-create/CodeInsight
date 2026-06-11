#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> Cij(H, vector<char>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> Cij[i][j];
        }
    }

    for(int i=0; i<2*H; i++){
        for(int j=0; j<W-1; j++){
            cout << Cij[(int)((i)/2)][j]; 
        }
        cout << Cij[(int)((i)/2)][W-1] << endl;
    }

    return 0;
}