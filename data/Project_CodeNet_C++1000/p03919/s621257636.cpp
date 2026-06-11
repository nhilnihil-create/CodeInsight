#include <iostream>
#include <string>

using namespace std;

int main(){
    int h, w;
    string ary[30][30];
    string str[30] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for(int j = 1 ; j <= w ; j++){
            cin >> ary[i][j];
        }
    }
    for(int i = 1 ; i <= h ; i++){
        for(int j = 1 ; j <= w ; j++){
            if(ary[i][j] == "snuke"){
                cout << str[j-1] << i << '\n';
            }
        }
    }
}