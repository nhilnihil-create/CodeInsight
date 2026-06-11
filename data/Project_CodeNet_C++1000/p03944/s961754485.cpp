#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    vector<int> x(N), y(N), a(N);
    vector<vector<int>> HW(H, vector<int>(W, 0));
    for (int i = 0; i < N; i++) {
        cin >> x.at(i) >> y.at(i) >> a.at(i);
    }
    
    for (int i = 0; i < N; i++) {
        if (a.at(i) == 1) {
            if (x.at(i) != 0) {
                for (int j = 0; j < H; j++) {
                    for (int k = 0; k < x.at(i); k++) {
                        HW.at(j).at(k) = 1;
                    }
                }
            }
        } else if (a.at(i) == 2) {
            if (x.at(i) != W) {
                for (int j = 0; j < H; j++) {
                    for (int k = x.at(i); k < W; k++) {
                        HW.at(j).at(k) = 1;
                    }
                }
            }
        } else if (a.at(i) == 3) {
            if (y.at(i) != 0) {
                for (int j = 0; j < y.at(i); j++) {
                    for (int k = 0; k < W; k++) {
                        HW.at(j).at(k) = 1;
                    }
                }
            }
        } else {
            if (y.at(i) != H) {
                for (int j = y.at(i); j < H; j++) {
                    for (int k = 0; k < W; k++) {
                        HW.at(j).at(k) = 1;
                    }
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (HW.at(i).at(j) == 0) sum++;
        }
    }
    cout << sum << endl;
}
