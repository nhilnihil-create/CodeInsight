#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans = 0;

void dfs(string s, int count, ll total, ll now){
    if(count==s.size()){
        ans += total + now;
        return;
    }
    ll tmp = s[count] - '0';
    dfs(s, count+1, total+now, tmp);
    dfs(s, count+1, total, now*10+tmp);
}

int main() {
    string S;
    cin >> S;
    dfs(S, 1, 0, S[0]-'0');

    cout << ans << endl;
}