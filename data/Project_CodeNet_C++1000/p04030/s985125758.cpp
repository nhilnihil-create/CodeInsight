#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
#define v(i) vector<i>
#define vv(i) vector<vector<i>>
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換

int main() {
    string s;
    cin>>s;
    v(char) ans;
    rep(i,s.size()){
        if(s[i] == '0'){
            ans.push_back('0');
        }else if(s[i] == '1'){
            ans.push_back('1');
        }else if(s[i] == 'B' && !ans.empty()){
            ans.pop_back();
        }
        }
        rep(i,ans.size()){
            cout<<ans[i];
        }
            return 0;
}
