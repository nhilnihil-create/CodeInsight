#include <vector>
#include <iostream>
using namespace std;

vector<int> mkit(int N, int n) {
    int r = N % n;
    int m = N / n;
    int x = m + 2;
    vector<int> ret(N, 0);
    for (int i = 0; i < m; i++) {
        ret[i*n] = x;
        ret[i*n+n-1] = -x-1;
    }
    ret[N-1] = x;
    return ret;
}

int main() {
    int H, W, h, w; cin >> H >> W >> h >> w;
    if (H % h) {
        vector<int> v = mkit(H, h);
        cout << "Yes\n";
        for (int x : v)
            for (int j = 0; j < W; j++)
                cout << x << (j == W-1 ? '\n' : ' ');
    } else if (W % w) {
        vector<int> v = mkit(W, w);
        cout << "Yes\n";
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                cout << v[j] << (j == W-1 ? '\n' : ' ');
    } else
        cout << "No\n";
}
