#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int H,W;

    cin >> H >> W;

    vector<vector<char>> pic(H + 2,vector<char>(W + 2));

    for(int i = 0; i < pic.size(); i++){
        for(int j = 0; j < pic.at(i).size(); j++){
            if(i == 0 || i == (pic.size() - 1)){
                pic.at(i).at(j) = '#';
            }else{
                if(j == 0 || j == (pic.at(i).size() - 1)){
                    pic.at(i).at(j) = '#';
                }else{
                    cin >> pic.at(i).at(j);
                }
            }
        }
    }

    for(int i = 0; i < pic.size(); i++){
        for(int j = 0; j < pic.at(i).size(); j++){
            cout << pic.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}