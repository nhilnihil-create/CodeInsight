#include<bits/stdc++.h>
using namespace std;
int main(){
    int W, H, N;
    cin >> W >> H >> N;
    vector<vector<int>> A(W, vector<int>(H));
    int x, y, a; 
    for(int i = 0; i < N; i++){
        cin >> x >> y >> a;
        if(a == 1){
            for(int j = 0; j < x; j++){
                for(int k = 0; k < H; k++){
                    A.at(j).at(k)++;
                }
            }
        }
        if(a == 2){
            for(int j = x; j < W; j++){
                for(int k = 0; k < H; k++){
                    A.at(j).at(k)++;
                }
            }
        }
        if(a == 3){
            for(int j = 0; j < W; j++){
                for(int k = 0; k < y; k++){
                    A.at(j).at(k)++;
                }
            }
        }
        if(a == 4){
            for(int j = 0; j < W; j++){
                for(int k = y; k < H; k++){
                    A.at(j).at(k)++;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            if(A.at(i).at(j) == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}