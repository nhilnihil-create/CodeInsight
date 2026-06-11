#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> a(N), grid(H*W);
    for(int i=0; i<N; i++) {
        cin >> a[i];
    }

    int s = 0;
    for(int i=0; i<N; i++) {
        for(int j=s; j<s+a[i]; j++) {
            grid[j] = i+1;
        }
        s += a[i];
    }

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(i%2) {
                cout << grid[i*W + W-1-j] << " ";
            } else {
                cout << grid[i*W + j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
