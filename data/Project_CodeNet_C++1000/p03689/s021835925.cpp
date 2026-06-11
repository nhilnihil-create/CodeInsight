#include <iostream>
using namespace std;

const int bignum = 100000000;

int main()
{
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    if(H % h == 0 && W % w == 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(i % h == 0 && j % w == 0) cout << bignum + 1 << " ";
            else if((i + 1) % h == 0 && (j + 1) % w == 0) cout << -h * w - bignum << " ";
            else cout << 1 << " ";
        }
        cout << endl;
    }
}