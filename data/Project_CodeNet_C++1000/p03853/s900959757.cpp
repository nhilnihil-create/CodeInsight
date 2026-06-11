#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using str = string;
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;
using vc = vector<char>;
using vcc = vector<vc>;
 
int main() {
    int H, W;
    cin >> H >> W;
    vcc C(H, vc(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> C[i][j];
        }
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << C[i][j];
        }
        cout << endl;
        for(int j = 0; j < W; j++) {
            cout << C[i][j];
        }
        cout << endl;
    }
    return 0;
}