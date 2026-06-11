#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    vector <vector<char>> map(h+2,vector<char>(w+2,'#'));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> map[i+1][j+1];
        }
    }
    for(int i = 0; i < map.size(); i++){
        for( int j = 0; j < map[i].size(); j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}