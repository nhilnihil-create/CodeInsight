#include<bits/stdc++.h>
using namespace std;

int main(){
    size_t H, W;
    cin >> H >> W;
    size_t d;
    cin >> d;
    vector<vector<char>> c{{'R', 'G'}, {'B', 'Y'}};
    for(size_t i = 0; i < H; ++i, cout << endl)for(size_t j = 0; j < W; ++j)cout << c[(i + j) / d & 1][(i + W - j) / d & 1];
    return 0;
}