#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    vector<string> s(3);
    rep(i,3) cin >> s[i];
    map<char,string> mp;
    mp['a'] = s[0];
    mp['b'] = s[1];
    mp['c'] = s[2];
    char now = 'a';
    while(true){
        char n = mp[now][0];
        if(mp[now].size() == 0){
            char ans = now - 32;
            cout << ans << endl;
            return 0;
        }
        mp[now] = mp[now].substr(1);
        now = n;
    }
}