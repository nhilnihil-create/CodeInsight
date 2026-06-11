#include<bits/stdc++.h>
using namespace std;

int main(){
    size_t H, W, d;
    cin >> H >> W >> d;
    for(size_t i = 0; i < H; ++i, fputc('\n', stdout))for(size_t j = 0; j < W; ++j)fputc("RGBY"[((i + i + j + j) / d & 2) + ((i + W - j) / d & 1)], stdout);
    return 0;
}