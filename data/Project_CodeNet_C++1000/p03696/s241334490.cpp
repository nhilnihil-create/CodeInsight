#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()

string delete_pair(string s){
    string ret;
    for(char c : s){
        if(ret.empty()){
            ret.push_back(c);
            continue;
        }
        if(ret.back() == '(' && c == ')'){
            ret.pop_back();
            continue;
        }
        ret.push_back(c);
    }
    return ret;
}

signed main(){
    int n;
    string s;
    cin >> n >> s;
    string t = delete_pair(s);
    
    for(char &c : t){
        c = (c == ')' ? '(' :')');
    }
    
    int b = (int) t.length();
    rep(i, t.length()){
        if(t[i] == ')'){
            b = i; break;
        }
    }
    string ans = t.substr(0,b) + s + t.substr(b);
    cout << ans << endl;
}