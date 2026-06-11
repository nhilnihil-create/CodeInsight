#include<bits/stdc++.h>
using namespace std;

int main(){
    size_t H, W, d;
    cin >> H >> W >> d;
    for(size_t i = 0; i < H; ++i, cout << endl)for(size_t j = 0; j < W; ++j)cout << "RGBY"[((i + i + j + j) / d & 2) + ((i + W - j) / d & 1)];
    return 0;
}