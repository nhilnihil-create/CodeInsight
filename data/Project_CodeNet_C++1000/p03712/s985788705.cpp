#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for(int i = 0; i < H; i++){
        cin >> a.at(i);
    }
    for(int i = 0; i < H + 2; i++){
        if(i == 0 || i == H + 1){
            for(int j = 0; j < W + 2; j++){
                cout << "#";
            }
        }else{
            for(int j = 0; j < W + 2; j++){
                if(j == 0 || j == W + 1){
                    cout << "#";
                }else{
                    cout << (a.at(i - 1)).at(j - 1);
                }
            }
        }
        cout << endl;
    }
}