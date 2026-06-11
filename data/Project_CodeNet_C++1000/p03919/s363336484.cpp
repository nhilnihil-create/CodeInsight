#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

void solve();

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}

void solve() {
    int h,w;
    cin >> h >> w;
    string s[h][w];
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> s[i][j];
        }
    }
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(s[i][j] == "snuke") {
                cout << (char)('A' + (char)j) << (i+1) << endl;
            }
        }
    }


}