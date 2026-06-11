#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int h,w;
    string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> h >> w;
    vector<vector<string>> s(h, vector<string>(w));
    rep(i,h){
        rep(j,w){
            cin >> s[i][j];
        }
    }
    rep(i,h){
        rep(j,w){
            if(s[i][j] == "snuke"){
                cout << al[j] << i + 1 << endl;
            }
        }
    }
    return 0;
}