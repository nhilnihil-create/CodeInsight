#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) cin >> A[i][j];
    vector<vector<char>> Ae(H + 2, vector<char>(W + 2, '#'));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            Ae[i + 1][j + 1] = A[i][j];
        }
    }
    for(int i = 0; i < H + 2; i++){
        for(int j = 0; j < W + 2; j++){
            cout << Ae[i][j];
        }
        cout << endl;
    }
}
