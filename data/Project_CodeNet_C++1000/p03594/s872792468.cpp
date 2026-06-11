#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
    int h, w, d;
    cin >> h >> w >> d;
    vector<vector<int>> v(1002, vector<int>(1002, -1));
    array<bitset<1002>, 1002> use;
    map<pair<int,int>, pair<int,int>> p;

    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j){
            int x = i + j, y = i - j + 500;
            use[x].set(y);
        }

    if(d & 1){
        for(int i = 0; i < 1002; ++i)
            for(int j = 0; j < 1002; ++j)
                v[i][j] = i % 2;
    }else{
        for(int i = 0; i < 1002; ++i)
            for(int j = 0; j < 1002; ++j){
                int f1 = i % (2 * d) >= d;
                int f2 = j % (2 * d) >= d;
                v[i][j] = f1 + 2 * f2;
            }
    }

    auto print = [&]{
        string s = "RYGB";
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                int x = i + j, y = i - j + 500;
                cout << s[v[x][y]];
            }
            cout << endl;
        }
    };

    print();
}
