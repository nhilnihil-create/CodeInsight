#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    vector<vector<int>> inputs(N, vector<int>(3));
    rep(i, N){
        rep(j, 3){
            cin >> inputs.at(i).at(j);
        }
    }

    vector<vector<bool>> canvas(H, vector<bool>(W, true));
    for(vector<int> input : inputs){
        if(input.at(2) == 1){
            rep(i, H){
                rep(j, input.at(0)){
                    canvas.at(i).at(j) = false;
                }
            }
        } else if(input.at(2) == 2){
            rep(i, H){
                for(int j=input.at(0); j<W; j++){
                    canvas.at(i).at(j) = false;
                }
            }
        } else if(input.at(2) == 3){
            rep(i, W){
                rep(j, input.at(1)){
                    canvas.at(j).at(i) = false;
                }
            }
        } else if(input.at(2) == 4){
            rep(i, W){
                for(int j=input.at(1); j<H; j++){
                    canvas.at(j).at(i) = false;
                }
            }
        }
    }
    int ans = 0;
    for(vector<bool> row : canvas){
        for(bool c : row){
            if(c) ans++;
            // cout << c;
        }
    }
    cout << ans << endl;
}