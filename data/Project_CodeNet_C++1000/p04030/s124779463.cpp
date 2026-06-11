
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    string ans = "";
    rep(i,s.length()){
        if(!ans.empty() && s[i] == 'B'){
            int n = ans.length();
            ans.erase(n-1);
        }else if(s[i] == '0'){
            ans += '0';
        }else if(s[i] == '1'){
            ans += '1';
        }
    }
    cout << ans << endl;
    
    return 0;
}