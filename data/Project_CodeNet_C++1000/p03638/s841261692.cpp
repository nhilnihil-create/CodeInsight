#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, N;   cin >> H >> W;
    cin >> N;
    vector<int> color;
    for (int i = 0; i < N; i++) {
        int a;  cin >> a;
        while (a-- > 0)
            color.push_back(i+1);
    }
    
    vector<vector<int> > ans(H, vector<int>(W));

    int k = 0;
    for (int i = 0; i < H; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < W; j++)
                ans[i][j] = color[k++];
        }
        else {
            for (int j = W-1; j >= 0; j--)
                ans[i][j] = color[k++];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}