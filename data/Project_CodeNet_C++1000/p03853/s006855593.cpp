#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int h,w;
    cin >> h >> w;
    string s;
    vector<string> ans;
    rep(i,h){
        cin >> s;
        rep(j,2) ans.push_back(s);
        
    }
    rep(i,h*2){
        cout << ans[i] << endl;
    }
    return 0;
}