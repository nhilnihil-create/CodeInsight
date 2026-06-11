#include <bits/stdc++.h>
using namespace std;

//#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()

vector<pair<char,int>> runlength(string s) {
    vector<pair<char,int>> v;
    v.push_back({s[0],1});
    for(int i = 1; i < s.length(); i++){
        if(v.back().first == s[i]){
            v.back().second++;
        }else{
            v.push_back({s[i],1});
        }
    }
    return v;
}

signed main() {
    string s;
    cin >> s;
    auto rlv = runlength(s);
    
    int ans = INT_MAX;
    reps(c, 'a', 'z'){
        int max_streak = 0, now = 0;
        for(auto p : rlv){
            if(p.first == c){
                now = 0;
            }else{
                now += p.second;
                max_streak = max(max_streak, now);
            }
        }
        ans = min(max_streak, ans);
    }
    
    cout << ans << endl;
}