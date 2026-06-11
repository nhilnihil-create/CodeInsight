#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> c(h,vector<char>(w));
    for(auto& v:c){
        for(auto& e:v){
            cin >> e;
        }
    }
    for(auto& v:c){
        for(int i=0;i<2;i++){
            for(auto& e:v){
                cout << e;
            }
            cout << endl;
        }
    }
}