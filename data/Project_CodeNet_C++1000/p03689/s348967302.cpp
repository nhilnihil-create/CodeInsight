#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    if((H % h == 0) && (W % w == 0)){
        cout << "No" << endl;
        return 0;
    }
    /*bool checkH[600];
    bool checkW[600];
    for(int i = 1; i <= 550; i++){
        checkH[i] = false;
        checkW[i] = false;
    }
    for(int i = h; i <= H; i += h){
        checkH[i] = true;
    }
    bool checker = true;
    for(int i = H - h + 1; i <= H; i++){
        if(checkH[i]){
            checker = false;
        }
    }
    if(checker){
        checkH[H] = true;
    }
    checker = true;
    for(int i = w; i <= W; i += w){
        checkW[i] = true;
    }
    for(int i = W - w + 1; i <= W; i++){
        if(checkW[i]){
            checker = false;
        }
    }
    if(checker){
        checkW[W] = true;
    }
    int sum = 0;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(checkH[i] && checkW[j]){
                sum -= h * w;
            } else {
                sum += 1;
            }
        }
    } 
    if(sum <= 0){
        cout << "No" << endl;
        return 0;
    }*/
    cout << "Yes" << endl;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if((i % h == 0) && (j % w == 0)){
                cout << -1000000000;
            } else if(((i - 1) % h == 0) && ((j - 1) % w == 0)){
                cout << 1000000000 - w * h + 1;
            } else {
                cout << 1;
            }
            if(j < W){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
