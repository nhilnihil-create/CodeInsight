#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];

    rep(i,w+2){
        cout << "#";
    }
    cout << endl;
    
    rep(i,h){
        cout << "#";
        rep(j,w){
            cout << a[i][j];
        }
        cout << "#" << endl;
    }

    rep(i,w+2){
        cout << "#";
    }
    cout << endl;

    return 0;
}