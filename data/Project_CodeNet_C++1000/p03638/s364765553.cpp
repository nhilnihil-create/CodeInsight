#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> a(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> a.at(i);
    }

    int a_idx = 0;
    int n = a.at(a_idx);
    for ( int row = 0; row < H; row++ ) {
        vector<int> ans(W);
        for ( int col = 0; col < W; col++ ) {
            if ( n == 0 ) {
                a_idx++;
                n = a.at(a_idx);
            }
            ans.at(col) = a_idx + 1;
            n--;
        }
        for ( int i = 0; i < W; i++ ) {
            if ( row % 2 == 0 ) {
                cout << ans.at(i);
            }
            else {
                cout << ans.at(W-i-1);
            }
            if ( i != W-1 ) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
