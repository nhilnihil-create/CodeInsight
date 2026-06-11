#include <bits/stdc++.h>
#include <algorithm>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int H, W;
    map<int, char> mp;
    mp[1] = 'A';
    mp[2] = 'B';
    mp[3] = 'C';
    mp[4] = 'D';
    mp[5] = 'E';
    mp[6] = 'F';
    mp[7] = 'G';
    mp[8] = 'H';
    mp[9] = 'I';
    mp[10] = 'J';
    mp[11] = 'K';
    mp[12] = 'L';
    mp[13] = 'M';
    mp[14] = 'N';
    mp[15] = 'O';
    mp[16] = 'P';
    mp[17] = 'Q';
    mp[18] = 'R';
    mp[19] = 'S';
    mp[20] = 'T';
    mp[21] = 'U';
    mp[22] = 'V';
    mp[23] = 'W';
    mp[24] = 'X';
    mp[25] = 'Y';
    mp[26] = 'Z';
    vector<vector<string>> data(27, vector<string>(27));
    cin >> H >> W;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            cin >> data[i][j];
        }
    }

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (data[i][j] == "snuke") {
                cout << mp[j]; 
                cout << i << endl; 
            }
        }
    }
    return 0;
}
