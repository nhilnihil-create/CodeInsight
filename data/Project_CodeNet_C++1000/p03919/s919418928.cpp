#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int H, W;
    cin >> H >> W;

    string L = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char col = 0;
    int axis = 0;

    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            string S;
            cin >> S;
            if (S == "snuke"){
                col = L[j];
                axis = i + 1;
            }
        }  
    }


    cout << col << axis << endl;
}