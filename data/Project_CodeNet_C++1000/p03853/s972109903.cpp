#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char> (w));
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin >> c.at(i).at(j);
        }
    }
    int count = 0;
    for(int i = 0;i < 2 * h;i++){
        for(int j = 0;j < w;j++){
            cout << c.at(count).at(j);
        }
        if(i % 2 == 1)count++;
        cout << endl;
    }
}