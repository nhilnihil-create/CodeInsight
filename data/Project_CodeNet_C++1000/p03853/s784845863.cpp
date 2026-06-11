#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    vector<vector<char> > C(H, vector<char>(W));

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> C[i][j];
        }
    }

    for(int i = 0; i < H * 2; i++) {
        for(int j = 0; j < W; j++) {
            cout << C[i / 2][j];
        }
        cout << endl;
    }
}