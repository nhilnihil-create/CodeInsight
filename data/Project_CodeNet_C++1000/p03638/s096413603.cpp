#include "bits/stdc++.h"

using namespace std;

void next(pair<int, int>& curr, int W) {
    int i = curr.first;
    int j = curr.second;
    if (i % 2 == 0) {
        if (j == W - 1) {
            curr.first = i + 1;
            curr.second = j;
        }
        else {
            curr.first = i;
            curr.second = j + 1;
        }
    }
    else {
        if (j == 0) {
            curr.first = i + 1;
            curr.second = j;
        }
        else {
            curr.first = i;
            curr.second = j - 1;
        }
    }
}

void Main() {
    int H, W;
    cin >> H >> W;
    int N;
    cin >> N;
    vector<pair<int, int> > a(N, make_pair(0, 0));
    for (int i = 0; i < N; ++i) {
        a[i].first = i + 1;
        cin >> a[i].second;
    }

    vector<vector<int> > ans(H, vector<int>(W, 0));
    pair<int, int> curr = make_pair(-1, 0);
    for (int i = 0; i < N; ++i) {
        int color = a[i].first;
        int nc = a[i].second;
        for (int j = 0; j < nc; ++j) {
            next(curr, W);
            ans[curr.first][curr.second] = color;
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (j > 0) {
                cout << " ";
            }
            cout << ans[i][j];
        }
        cout << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
