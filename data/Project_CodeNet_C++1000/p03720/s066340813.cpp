#include <iostream>
#include <algorithm>

using namespace std;

int rdmap[51][51];

void solve() {
    int n,m;
    cin >> n >> m;
    for(int i=0; i < m; ++i){
        int ai, bi;
        cin >> ai >> bi;
        ++rdmap[ai][bi];
        ++rdmap[bi][ai];
    }
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            cnt += rdmap[i][j];
        }
        cout << cnt << endl;
    }

}

int main() {

    solve();
    return 0;
}
