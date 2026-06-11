#include<iostream>
#include<string>
#include <numeric>
using namespace std;
int H, W;
string s[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
string str;
int main() {
    cin >> H >> W;
    bool flag=true;
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            cin >> str;
            if(str == "snuke"){
                cout << s[j] << i+1 << endl;
                flag = false;
                break;
            }
        }
        if(!flag) break;
    } 
    return 0;
}