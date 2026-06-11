#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
// a b c d a
int main() {
    string s;
    cin >> s;
    int ans = s.size();
    for(char c : s) {
        int cnt = 0;
        rep(i,s.size()) {
            int j = i;
            while(j < s.size() && !((s[i]==c)^(s[j]==c))) j++;
            if(s[i]!=c) cnt = max(cnt, j-i);
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}