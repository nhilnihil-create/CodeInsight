#include <iostream>
#include <vector>
using namespace std;

void set_right(vector<vector<int>>& P, uint xBase) {
    if (xBase >= P[0].size()) return;
    for (uint x=xBase; x<P[0].size(); ++x) {
        for (uint y=0; y<P.size(); ++y) {
            P[y][x] = 0;
        }
    }
};

void set_left(vector<vector<int>>& P, uint xBase) {
    for (uint x=0; x<xBase; ++x) {
        for (uint y=0; y<P.size(); ++y) {
            P[y][x] = 0;
        }
    }
};

void set_bottom(vector<vector<int>>& P, uint yBase) {
    for (uint y=0; y<yBase; ++y) {
        for (uint x=0; x<P[y].size(); ++x) {
            P[y][x] = 0;
        }
    }
};

void set_top(vector<vector<int>>& P, uint yBase) {
    if (yBase >= P.size()) return;
    for (uint y=yBase; y<P.size(); ++y) {
        for (uint x=0; x<P[y].size(); ++x) {
            P[y][x] = 0;
        }
    }
};

int main() {
    uint W, H, N;
    cin >> W >> H >> N;
    vector<vector<int>> P(H, vector<int>(W, 1));

    for (size_t i=0; i<N; ++i) {
        uint x, y, a;
        cin >> x >> y >> a;

        if (a == 1) {
            set_left(P, x);
        }
        else if (a == 2) {
            set_right(P, x);
        }
        else if (a == 3) {
            set_bottom(P, y);
        }
        else if (a == 4) {
            set_top(P, y);
        }
    }

    int area = 0;
    for (uint y=0; y<P.size(); ++y) {
        for (uint x=0; x<P[0].size(); ++x) {
            area += P[y][x];
        }
    }
    cout << area << endl;
}