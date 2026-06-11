#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {

    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
    }

    vector<vector<int>> grid(h, vector<int>(w));
    int idx = 0;
    rep(i, h){
        if(i%2 == 0){
            rep(j, w){
                grid[i][j] = idx+1;
                if(--a[idx] == 0){
                    idx++;
                }
            }
        }
        else{
            for(int j=w-1; j>=0; --j){
                grid[i][j] = idx+1;
                if(--a[idx] == 0){
                    idx++;
                }
            }
        }
    }
    
    rep(i, h){
        rep(j, w){
            if(j != w-1){
                cout << grid[i][j] << " ";
            }
            else{
                cout << grid[i][j] << endl;
            }
        }
    }

    return 0;
}
