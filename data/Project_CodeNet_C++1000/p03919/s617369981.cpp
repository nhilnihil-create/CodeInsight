#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    //aからなんばんめか，は (static_cast<int> ("調べたいアルファベット")) - (statc_cast<int> ("a") + 1)
    //input
    int h;
    int w;
    cin >> h >> w;
    //int width = static_cast<int> (w) - static_cast<int> ('a') + 1;
    //cout << width << endl;
    string matrix[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> matrix[i][j];
        }
    }

    //main
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(matrix[i][j] == "snuke"){
                //
                cout << static_cast<char> ('a' + j - 32) << i+1 << endl;
                break;
            }
        }
    }
    return 0;
}