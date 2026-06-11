#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <functional>
#include <array>

using namespace std;
using P = pair<int, int>;

int main(){
    int64_t H, W, N;
    cin >> H >> W >> N;

    map<P, int> m;
    vector<int64_t> ans(10, 0);
    ans[0] = (H - 2) * (W - 2);
    for(int i = 0; i < N; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        for(int x = -1; x <= 1; ++x) for(int y = -1; y <= 1; ++y){
            int nx = b + x;
            int ny = a + y;
            if(0 < nx && nx < W-1 && 0 < ny && ny < H-1){
                ans[m[P(ny, nx)]] --;
                m[P(ny, nx)] ++;
                ans[m[P(ny, nx)]] ++;
            }
        }
    }

    for(int i = 0; i <= 9; ++i){
        cout << ans[i] << endl;
    }
}