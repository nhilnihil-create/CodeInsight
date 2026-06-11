#include<iostream>
#include<vector>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    
    char data[h+2][w+2];
    for(int i = 0; i < h+2; i++){
        for(int j = 0; j < w+2; j++){
            data[i][j] = '#';
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> data[i+1][j+1];
        }
    }
    for(int i = 0; i < h+2; i++){
        for(int j = 0; j < w+2; j++){
            cout << data[i][j];
        }
        cout << endl;
    }
    return 0;

}