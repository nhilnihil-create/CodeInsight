#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H,W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0;i < H; ++i){
        cin >> S[i];
    }
    for(int i = 0; i < H; ++i){
        cout << S[i] << endl;
        cout << S[i] << endl;
    }
    return 0;
}