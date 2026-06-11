#include<bits/stdc++.h>
using namespace std;

int main(){
    size_t H, W;
    cin >> H >> W;
    size_t d;
    cin >> d;if(d & 1){
        string s(H + W, 'R');
        for(size_t i = 0; i < H + W; ++i)s[i] ^= (i & 1) << 4;
        for(size_t i = 0; i < H; ++i, cout << endl)copy(s.begin() + i, s.begin() + i + W, ostream_iterator<char>(cout));
    }else{
        vector<vector<char>> c{{'R', 'G'}, {'B', 'Y'}};
        for(size_t i = 0; i < H; ++i, cout << endl)for(size_t j = 0; j < W; ++j)cout << c[(i + j) / d & 1][(i + W - j) / d & 1];
    }
    return 0;
}