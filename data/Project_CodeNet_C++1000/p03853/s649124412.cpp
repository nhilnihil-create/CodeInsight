#include <bits/stdc++.h>
using namespace std;

int main(){

    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            cin >> c.at(i).at(j);
        }
    }

    vector<vector<char>> cc(2*h, vector<char>(w));
    int idx = 0;
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            cc.at(idx).at(j) = c.at(i).at(j);
            cc.at(idx+1).at(j) = c.at(i).at(j);
        }
        idx += 2;
    }

    for (int i=0; i<2*h; i++){
        for (int j=0; j<w; j++){
            cout << cc.at(i).at(j);
        }
        cout << endl;
    }
    return 0;
}