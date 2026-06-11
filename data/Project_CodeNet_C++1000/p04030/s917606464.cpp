#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}
 
int main() {
    string ans = "";
    string s;
    cin >> s;
    int n = s.size();
    rep(i,n) {
        if(s[i] == '0') ans += '0';
        else if(s[i] == '1') ans += '1';
        else if(s[i] == 'B' && !ans.empty()) ans.erase(ans.size() - 1);
        else continue;
    }
    cout << ans << endl;
}