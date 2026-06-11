#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;

signed main(){
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    auto f = [&]{
        if(h == 1 && w == 1){
            cout << "No" << endl;
            return ;
        }
        i64 sum = 0;
        i64 mul = (1e9 - 1) / (a * b - 1);
        vector<vector<i64>> v(h, vector<i64>(w));
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                v[i][j] = mul;
                if(i % a == a - 1 && j % b == b - 1)
                    v[i][j] = -mul * (a * b - 1) - 1;
                sum += v[i][j];
            }
        }
        if(sum <= 0){
            cout << "No" << endl;
            return ;
        }
        cout << "Yes" << endl;
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                cout << v[i][j] << (j == w - 1 ? "\n" : " ");
            }
        }
        return ;
    };
    f();

}
