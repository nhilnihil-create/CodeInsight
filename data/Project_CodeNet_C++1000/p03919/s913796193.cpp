#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main () {
    int H, W;
    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        vector<string> S_i(W);
        for (int j = 0; j < W; j++) {
            cin >> S_i[j];
            
            if (S_i.at(j) == "snuke") {
                cout << char('A' + j) << i + 1 << endl;
                break;    
            }
        }
    }

    return 0;

}