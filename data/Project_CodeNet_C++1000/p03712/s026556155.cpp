#include<iostream>
using namespace std;
int main(){
    int H,W;
    cin >> H >> W;
    
    string S[100];
    for(int i = 0; i < H; i++){
        cin >> S[i];
    }
    
    for(int i = 0; i < W + 2; i++){
        cout << "#";
    }cout << endl;
    
    for(int i = 0; i < H; i++){
        cout << "#" << S[i] << "#" << endl;
    }
    
    for(int i = 0; i < W + 2; i++){
        cout << "#";
    }cout << endl;
    
}