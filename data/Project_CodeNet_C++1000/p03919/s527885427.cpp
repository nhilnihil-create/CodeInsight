#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
    int a, b, c, d, n, x, y;
    string s, t;


    auto Yes = [&](bool t){
        cout << (t ? "Yes" : "No") << endl;
    };
    auto YES = [&](bool t){
        cout << (t ? "YES" : "NO") << endl;
    };
    auto tri = [&](bool t, string a, string b){
        cout << (t ? a : b) << endl;
    };

    cin >> a >> b;
    for(int i = 0; i < a; ++i){
        for(int j = 0; j < b; ++j){
            cin >> s;
            if(s == "snuke"){
                cout << char('A' + j) << i + 1 << endl;
                return 0;
            }
        }
    }
}
