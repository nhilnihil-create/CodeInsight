#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    int h, w;
    cin >> h >> w;
    char a[h][w];
    rep(i, h){
        rep(j, w){
            cin >> a[i][j];
        }
    }
    rep(i, w+2) cout << "#";
    cout << endl;
    rep(i, h){
        cout << "#";
        rep(j, w) cout << a[i][j];
        cout << "#" << endl;
    }
    rep(i, w+2) cout << "#";
    cout << endl;
    return 0;
}