#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

vector<vector<bool>> TFcombination(int n){
    vector<vector<bool>> ans(pow(2, n), vector<bool>(n));
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            ans[i][j] = i >> j & 1;
        }
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    int len = s.size();
    vector<vector<bool>> isPlus = TFcombination(len - 1);
    ll ans = 0;
    for(auto x : isPlus){
        ll tmp = 0;
        for(int i = 0; i < len; i++){
            tmp += s[i] - '0';
            if(i == len - 1) break;
            if(x[i]){
                ans += tmp;
                tmp = 0;
            }
            else{
                tmp *= 10;
            }
        }
        ans += tmp;
    }

    cout << ans << endl;
    return 0;
}