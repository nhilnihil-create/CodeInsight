#include<bits/stdc++.h>
using namespace std;

int main(){


    int H, W, h, w; cin >> H >> W >> h >> w;
    vector<vector<int> > a(H, vector<int> (W, 2000));
    
    for(int i = h - 1; i < H; i += h){
        for(int j = w - 1; j < W; j += w){
            a[i][j] = -2000 * (h * w - 1) - 1;
        }
    }

    int sum = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            sum += a[i][j];
        }
    }

    if(sum > 0){
        cout << "Yes" << endl;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }else cout << "No" << endl;
    return 0;
}