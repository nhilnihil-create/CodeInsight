#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    for(int i = 0; i < h; i++){
        cin >> c[i];
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < w; k++){
                cout << c[i][k];
            }
            cout << endl;
        }
    }
    return 0;
}