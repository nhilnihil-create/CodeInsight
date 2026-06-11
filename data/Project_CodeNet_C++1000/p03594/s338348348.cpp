#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int H, W, d;
char grid[2][2] = {{'R', 'Y'},
                   {'G', 'B'}};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> H >> W >> d;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            int x = i - j + H + W;
            int y = i + j + H + W;
            x /= d;
            y /= d;
            cout << grid[x & 1][y & 1];
        }
        cout << endl;
    }
}
