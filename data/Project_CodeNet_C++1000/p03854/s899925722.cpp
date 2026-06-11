#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<bool> dp(100005, false);
    dp[0] = true;
    rep(i,s.size()-4){
        if(!dp[i]) continue;
        if(s[i] == 'd' && s[i+1] == 'r' && s[i+2] == 'e' && s[i+3] == 'a' && s[i+4] == 'm') dp[i+5] = true;
        if(s[i] == 'd' && s[i+1] == 'r' && s[i+2] == 'e' && s[i+3] == 'a' && s[i+4] == 'm' && s[i+5] == 'e' && s[i+6] == 'r') dp[i+7] = true;
        if(s[i] == 'e' && s[i+1] == 'r' && s[i+2] == 'a' && s[i+3] == 's' && s[i+4] == 'e') dp[i+5] = true;
        if(s[i] == 'e' && s[i+1] == 'r' && s[i+2] == 'a' && s[i+3] == 's' && s[i+4] == 'e' && s[i+5] == 'r') dp[i+6] = true;
    }
    if(dp[s.size()]) cout << "YES" << endl;
    else cout << "NO" << endl;
}