#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    set<char> se;
    rep(i, n)se.insert(s[i]);
    int ans = 1000;
    for(char c : se){
        string t = s;
        int cnt = 0;
        rep(i, n){
            bool val = true;
            rep(j, t.size())if(t[j] != c)val = false;
            if(val){
                cnt = i;
                break;
            }else{
                string next = "";
                rep(j, t.size()-1){
                    if(t[j] == c || t[j+1] == c)next += c;
                    else next += '?';
                }
                t = next;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}