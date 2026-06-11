#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

string d[4] = {"dream", "dreamer", "erase", "eraser"};

int main() {
    string s;
    cin >> s;
    reverse(all(s));
    rep(i,4) reverse(all(d[i]));
    bool ok = true;
    for(int i = 0; i < s.size();) {
        bool oki = false;
        rep(j,4) {
            string t = d[j];
            if(s.substr(i,t.size())==t) {
                oki = true;
                i += t.size();
            }
        }
        if(!oki){
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}