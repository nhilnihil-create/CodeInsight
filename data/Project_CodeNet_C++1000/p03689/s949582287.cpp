#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W, h, w;
    cin >> H >> W >> h >> w;

    if(H % h == 0 && W % w == 0){
        cout << "No" << endl;
        return 0;
    }

    long long int minus = (H / h) * (W / w);
    long long int plus  = H * W - minus;
    long long int x = plus - minus * (h*w - 1);

    if(x < 0){
        cout << "No" << endl;
        return 0;
    }

    long long int p = (minus + x) / x;
    long long int m = - p * (h * w - 1) - 1;

    if(p > 1e9 || m < -1e9){
        cout << "No" << endl;
        return 0;
    }

    vector<vector<long long int>> a(H, vector<long long int>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            a[i][j] = p;
            if((i+1) % h == 0 && (j+1) % w == 0) a[i][j] = m;
        }
    }

    cout << "Yes" << endl;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << a[i][j];
            if(j == W-1) break;
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}