#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int h,w, n;
    cin >> h >> w;
    cin >> n;
    int grid[h*w];
    int last = 0;
    for (int i=0; i<n; ++i) {
        int ai;
        cin >>ai;
        for (int j = 0; j < ai; ++j) {
            grid[last + j] = i+1;
        }
        last += ai;
    }
    for (int i=0; i<h; ++i) {
        if (i%2 == 0) {
            for (int j=0; j<w; ++j) {
                cout << grid[w*i + j] << " ";
            }
            cout << '\n';
        } else {
            for (int j=w-1; j >=0; --j) {
                cout << grid[w*i +j] << " " ;
            }
            cout << '\n';
        }
    }

}

int main() {

	solve();
    return 0;
}
